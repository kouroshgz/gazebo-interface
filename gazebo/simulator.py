from ast import Raise
import asyncio
import sys
import math
import pygazebo
import pygazebo.msg.factory_pb2
import pygazebo.msg.vector3d_pb2
import pygazebo.msg.world_control_pb2
import pygazebo.msg.vector3d_pb2
# source $(poetry env info --path)/bin/activate
sys.path.insert(0, './util/pygazebo/pygazebo/msg/')
sys.path.insert(0, './util/pygazebo/')
import scenic_obj_info_pb2 as scenic_obj_info_pb2
import scenic_delete_models_pb2 as scenic_delete_models_pb2
from scenic.core.simulators import Simulator, Simulation
from scenic.core.vectors import Vector
from scipy.spatial.transform import Rotation as R

# TODO: 
# overwrite updateObjects() to wait on event, then call super.updateObjects, so that getProps no longer needs to be async
# write system such that theres only one mass iteration following all object spawns

class GazeboSimulator(Simulator):

    def __init__(self):
        print("in init")
        self.timeout = 30
        self.loop = asyncio.new_event_loop()
        asyncio.set_event_loop(self.loop)
        self.simulationCount = 0
        # messages to enable stepping through simulation and deleting dynamic objects + resetting non-dynamic objects
        self.connected = False
        async def a_connect(self):
            for i in range(self.timeout):
                try:
                    await asyncio.sleep(1)
                    print("in connect")
                    self.manager = await pygazebo.connect()
                    self.connected = True
                    print("connected!")
                    break
                except Exception as e:
                    print("Connection Failed: " + str(e))
                    break
            await asyncio.sleep(1)
        self.loop.run_until_complete(a_connect(self))
       
        
    def createSimulation(self, scene, verbosity=0):
        self.simulationCount += 1
        return GazeboSimulation(scene, self.manager, self.connected, self.loop, self.simulationCount)

    def destroy(self):
        print("in simulator destroy")
        async def a_destroy(self):
            print ("in simulator async destroy")
            # await self.manager.stop()
            print("end async simulator destroy")
        self.loop.run_until_complete(a_destroy(self))
        print("end simulator destroy")
        pass

# Note: Currently assuming gazebo world is started in paused state via cli 
class GazeboSimulation(Simulation):
    def __init__(self, scene, manager, connected, loop, simulationCount):
        print("in init of GazeboSimulation")
        super().__init__(scene)
        # pygazebo connection manager
        self.manager = manager
        # track # of simulations to try and work around multiple publisher issue until un-advertising is figured out
        self.simulationCount = simulationCount
        # stores object properties of all dynamic objects in simulation
        self.object_map = dict()
        # stores flags for per-object callback sync
        self.callbackMap = dict()
        # messages to enable stepping through simulation and deleting dynamic objects + resetting non-dynamic objects
        self.wc_step  = pygazebo.msg.world_control_pb2.WorldControl()
        self.wc_step.step = True
        self.delete_msg = scenic_delete_models_pb2.ScenicDeleteModels()
        self.delete_msg.reset = True
        self.delete_msg.clearAll = True
        self.connected = connected
        self.loop = loop
        # event to act as a lock for update info, making sure it doesnt occur until all callbacks complete
        self.objectDataEvent = asyncio.Event()
        # self.objectDataEvent.clear()
        # self.objectDataEvent.set()
        # need a count of exactly how many dynamic objects exist in scene
        self.eventCounter = 0
        for obj in scene.objects:
            if (hasattr(obj, "modelSDF")):
                self.eventCounter+=1
        # initCount serves to preserve the initial dynamic object count
        self.initCount = self.eventCounter
        self.numSpawns = 0
        print(self.initCount)
        #advertises necessary topics and wipes world of any dynamic objects.
        def advertise(self):
            print("in advertise")
            if self.simulationCount > 1:
                return
            async def a_advertise(self):
                print("in async advertise")
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
                    # breakpoint()
                    print("In callback: numSpawns is " + str(self.numSpawns))
                    stats = scenic_obj_info_pb2.ScenicObjectInfo()
                    stats.ParseFromString(data)
                    print("obj in callback's name: " + stats.name)
                    self.callbackMap[stats.name] = True
                    # on each update, rewrite current stats for the target object
                    self.object_map[stats.name] = stats
                    print("In callback, " + str(len(self.callbackMap)) + " unique callbacks")
                    if (len(self.callbackMap) == self.initCount):
                        self.objectDataEvent.set()
                    # print(self.object_map)
                self.stats_subscriber  = await self.manager.subscribe(
                    '/gazebo/default/scenic_model_stats', "scenic_obj_info_msgs.msgs", callback
                )
                # delete all dynamic objects, reset world
                await self.delete_publisher.publish(self.delete_msg)
                print("end async advert")
            self.loop.run_until_complete(a_advertise(self))
            print("end advertise")

        if self.connected is True:
            print("ADVERTISING")
            advertise(self)
        else:
            print("Error Not Connected to Pygazebo")
            return
        # reverse list to see if gazebo is ignoring first spawn message
        # t = reversed(scene.objects)
        for obj in scene.objects:
            if (hasattr(obj, "modelSDF")):
                self.createObjectInSimulator(obj)
            print("Object: " + str(obj))

    # note: 
    # have to reset counter and event at each time step, including initial time step (0)
    def step(self):
        # clears the event
        self.objectDataEvent.clear()
        # reinitialize the event counter to initial dynamic object count (this assumes the only deletes that occur are complete)
        self.eventCounter = self.initCount
        print("in step")
        async def a_step(self):
            print("in a_step")
            await self.world_publisher.publish(self.wc_step)
            print("end a_step")
        self.loop.run_until_complete(a_step(self))
        print("end step")
    
    def internal_step(self):
        async def a_internal_step(self):
            print("internal gazebo step")
            await self.world_publisher.publish(self.wc_step)
            await asyncio.sleep(1)
        self.loop.run_until_complete(a_internal_step(self))
    
    # currently assuming that object is some kind of sdf string
    def createObjectInSimulator(self, obj):
        print("in create object")
        self.numSpawns +=1
        async def a_createObjectInSimulator(self, obj):
            # currently assume desired positions/orientations are specified in the SDF, make more dynamic later
            print("in factory!")
            # print(obj)
            factory_msg = pygazebo.msg.factory_pb2.Factory()
            factory_msg.sdf = obj.modelSDF
            # print(factory_msg.sdf)
            await asyncio.sleep(1)
            await self.factory_publisher.publish(factory_msg)
            print("end async model spawn ")
        self.loop.run_until_complete(a_createObjectInSimulator(self, obj))        

    # overwrite updateObjects
    def updateObjects(self):
        while len(self.callbackMap) != self.initCount:
            self.internal_step()
        super().updateObjects()


    def getProperties(self, obj, properties):
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
        print(values)
        return values        
    def destroy(self):
        print("in simulation destroy")
        async def a_destroy(self):
            print("in async simulation destroy")
            # await self.world_publisher.remove()
            # await self.factory_publisher.remove()
            # await self.delete_publisher.remove()
            # await self.stats_subscriber.remove()
            print("end async simulation destroy")
        self.loop.run_until_complete(a_destroy(self))
        print("end simulation destroy")
    
