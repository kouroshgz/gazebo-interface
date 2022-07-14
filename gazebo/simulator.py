from ast import Raise
import asyncio
import sys
import math
import pygazebo
import pygazebo.msg.factory_pb2
import pygazebo.msg.vector3d_pb2
import pygazebo.msg.world_control_pb2
import pygazebo.msg.vector3d_pb2
sys.path.insert(0, '../pygazebo/msg/')
sys.path.insert(0, '../pygazebo/')
import scenic_obj_info_pb2 as scenic_obj_info_pb2
import scenic_delete_models_pb2 as scenic_delete_models_pb2
from scenic.core.simulators import Simulator, Simulation
from scenic.core.vectors import Vector
from scipy.spatial.transform import Rotation as R

# TODO: 
# - verify async method works
# - verify spawn works
# - heading conversion

class GazeboSimulator(Simulator):
    def __init__(self):
        self.timeout = 30

    async def connect(self):
        for i in range(self.timeout):
            try:
                self.manager = await pygazebo.connect()
                break
            except Exception as e:
                print("Connection Failed: " + str(e))
                return
        await asyncio.sleep(1)
        
    def createSimulation(self, scene, verbosity=0):
        self.scenario_number += 1
        return GazeboSimulation(scene, self.manager)

    async def destroy(self):
        await self.manager.stop()

# Note: Currently assuming gazebo world is started in paused state via cli 
class GazeboSimulation(Simulation):
    async def __aenter__(self, scene, manager):
        super().__init__(scene)
        # pygazebo connection manager
        self.manager = manager
        # stores object properties of all dynamic objects in simulation
        self.object_map = dict()
        # advertise / subscribe to relevant topics 
        self.world_publisher = await self.manager.advertise(
            '/gazebo/default/world_control',
            'gazebo.msgs.WorldControl'
            )
        self.factory_publisher = await self.manager.advertise(
            '/gazebo/default/factory',
            'gazebo.msgs.Factory'
        )
        self.delete_publisher = await self.manager.advertise(
            "/gazebo/default/scenic_delete_models", 
            "scenic_delete_models_msgs.msgs"
        )            
        def callback(data):
            stats = scenic_obj_info_pb2.ScenicObjectInfo()
            stats.ParseFromString(data)
            # on each update, rewrite current stats for the target object
            self.object_map[stats.name] = stats
        self.stats_subscriber  = await self.manager.subscribe(
            '/gazebo/default/scenic_model_stats', "scenic_obj_info_msgs.msgs", callback
        )
        self.object_map = dict()
        # messages to enable stepping through simulation and deleting dynamic objects + resetting non-dynamic objects
        self.wc_step  = pygazebo.msg.world_control_pb2.WorldControl()
        self.wc_step.step = True
        self.delete_msg = scenic_delete_models_pb2.ScenicDeleteModels()
        self.delete_msg.reset = True
        self.delete_msg.clearAll = True
        # webots example does some object instantiation here, should consider if its necessary for gazebo
        # delete all dynamic objects, reset world
        await self.delete_publisher.publish(self.delete_msg)

    async def step(self):
        await self.world_publisher(self.wc_step)

    # currently assuming that object is some kind of sdf string
    async def createObjectInSimulator(self, obj):
        # currently assume desired positions/orientations are specified in the SDF, make more dynamic later
        factory_msg = pygazebo.msg.factory_pb2.Factory()
        factory_msg.sdf = obj.modelSDF
        await self.factory_publisher.publish(factory_msg)

    async def getProperties(self, obj, properties):
        # position + elevation
        pos_x = self.object_map[obj.name].position.x
        pos_y = self.object_map[obj.name].position.y
        scenic_position = Vector(pos_x, pos_y)
        scenic_elevation = self.object_map[obj.name].position.z
        # velocity + speed
        vel_x = self.object_map[obj.name].linVelocity.x
        vel_y = self.object_map[obj.name].linVelocity.y
        scenic_velocity = (vel_x, vel_y)
        scenic_speed = math.hypot(*scenic_velocity)
        # angular speed
        scenic_ang_speed = self.object_map[obj.name].angVelocity.y
        # converting quaternion to scenic heading
        py_quat = [self.object_map[obj.name].orientation.x, self.object_map[obj.name].orientation.y, self.object_map[obj.name].orientation.z, self.object_map[obj.name].orientation.w]
        r = R.from_quat(py_quat)
        heading_array = r.as_euler('zxy')
        values = dict(
	    position=scenic_position,
	    elevation=scenic_elevation,
	    heading=heading_array[0],
	    velocity=scenic_velocity,
	    speed=scenic_speed,
	    angularSpeed=scenic_ang_speed,
        )
        return values

    async def destroy(self):
        await self.world_publisher.remove()
        await self.factory_publisher.remove()
        await self.delete_publisher.remove()
        await self.stats_subscriber.remove()
    



    

