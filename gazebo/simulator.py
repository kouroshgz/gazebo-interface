""" 
Interface for the Gazebo robotics simulator

TODO:
    - figure out how to handle async loop process
    - get props for a given model, given that model info update seems to only trigger on certain events
            note: objects passed into scene
                for spawning iterate through objects and spawn accordingly
                can spawn through strings (read in sdf file, if needed append any universally necessary sensors)
    - discuss scenic specific data structures
    - discuss better launch options, resetting, etc.
            - need to be able to reset to a point prior to dynamically placed object spawn
                - could potentially leave this for later
                - then need to remember to what you made
                    - simulator object : can make multiple scenes
                    - we'd want simulation class to remove all objects it creats on init
                    - 
    - discuss specifics on whats needed to init the simulator
    - discuss error checks, coordinate systems, etc.
            gazebo needs x->y to be clockwise
            likely fine on its own
            can just write a basic scene and check
self notes:
    - test1 is the one w/ the IMU
    - 
"""
import os
import asyncio
from util/pygazebo import pygazebo
from util/pygazebo/msg import pygazebo.msg.world_control_pb2
from util/pygazebo/msg import pygazebo.msg.factory_pb2
from util/pygazebo/msg import pygazebo.msg.quaternion_pb2
from util/pygazebo/msg import pygazebo.mgs.vector3d_pb2
from util/pygazebo/msg import pygazebo.msg.pose_pb2
from scipy.spatial.transform import Rotation as R
from scenic.core.simulators import Simulator, Simulation
from scenic.core.vectors import Vector
# should include pygazebo

# note:
# ideally want to start gazebo on its own
# and then be able to load a different world
# really need to be able to remove dynamically created objects
# call any deletion in the destructors for the simulator/simulation -- see carla simulator for example
# scenic considers everything to be blocking
# simulator should only run in the "step" function
class GazeboSimulator(Simulator):
    """
    `Simulator` object for Gazebo.
    
    Args:
        world_name: name of the world to launch gazebo with (if empty, then launches with blank world)
        port:       port to connect to gazebo on            (if empty, default is used)
        address:    address to connect to gazebo on         (if empty, default is used)
    """
    def __init__(self, world_name, port, address):
        super().__init__()
        # launch gazebo w/ provided world arg
        # can set to gzserver to disable GUI but for testing purpose, currently 
        # full server + client
        # -u arg starts simulation in paused state
        if world_name is "":
            os.system("gazebo -u")
        else:

            os.system("gazebo -u worlds/"+world_name+".world")
        # launch connection to pygazebo at default ports, etc (i think)
        # default port
        self.conn_port = 11345
        self.conn_addr = "127.0.0.1"
        if address is not "":
            self.conn_addr = address
        # not really sure that this is how you denote an empty int in python
        if port is not 0:
            self.conn_port = port
        self.manager = pygazebo.connect(address = self.conn_addr, port = self.conn_port)
        # advertise world control topic for pausing and stepping
        self.world_publisher = await self.manager.advertise(
                                '/gazebo/default/world_control',
                                'gazebo.msgs.WorldControl'
                                )
        # advertise topic for spawning models in world
        # note: can also instantiate objects inside the world file 
        self.model_publisher = await manager.advertise(
                        '/gazebo/default/factory',
                        'gazebo.msgs.Factory')

        # create a model/info subscriber
        # create a world stats subscriber
        # 
        
    def createSimulation(self, scene, verbosity=0):
        # unsure of what else to include here
        return GazeboSimulation(scene, self.world_publisher, self.model_publisher, self.manager)    

class GazeboSimulation(Simulation):
    """`Simulation` object for Gazebo.
    
    Attributes:
        world_publisher: publisher object for world_control messages
        model_publisher: publisher object for factory messages (model spawning)
    """
    def __init__(self, scene, world_publisher, model_publisher, manager, verbosity=0 ):
        self.world_publisher = world_publisher
        self.model_publisher = model_publisher
        self.objects         = scene.objects
        self.model_registry  = []

    # discuss scenic vector types
    # should probably incorporate exeptions/error checks
    """
    Function to spawn models in Gazebo.
    Arguments:
        name:   name of the model to spawn (if not unique, will have numbering appended to name, which can be disabled)
        vec:    vector containing x,y,z coords for positional placement
        quat:   vector containing x,y,z,w points for orientation data
        Note: 
            vec and quat assume that data is inserted in order specified in the above description
            model path is assumed to be default location for gazebo
            i.e. /usr/share/gazebo-11/models/[NAME]
    """
    def spawnModel(self, name, vec, quat):
        # create instances of the appropriate messages
        factory      = pygazebo.msg.factory_pb2.Factory()
        quaternion   = pygazebo.msg.quaternion_pb2.Quaternion() 
        vector3d     = pygazebo.msg.vector3d_pb2.Vector3d()
        pose         = pygazebo.msg.pose_pb2.Pose()

        # instantiate message fields
        # 2d Scenic: rotation across positive z axis
        # see scipy(?)
        # elevation prop  provides the "up" position
        quaternion.x = quat[0]
        quaternion.y = quat[1]
        quaternion.z = quat[2]
        quaternion.w = quat[3]

        vector3d.x   = vec[0]
        vector3d.y   = vec[1]
        vector3d.z   = vec[2]
        # copy data into nested message types
        pose.position.CopyFrom(vector3d)
        pose.orientation.CopyFrom(quaternion)

        # instantiate message for model that is to be spawned
        factory.sdf_filename = "model://"+name
        factory.pose.CopyFrom(pose)
        # seemingly mandatory sleep to get messages to send
        self.model_registry.append(name)
        await asyncio.sleep(1)
        await self.model_publisher.publish(factory)
    # retrieve properties from object
    # note: discerning between objects spawned in dynamically vs objects baked into world?
    """
    Name:        field in gazeboObject that specifies the model being referred to
    Properties:  ?
    Summary:
    For a given object, subscribes to its scenic_info topic and pulls its info, then updates properties
    Note:
    may actually be easier to do an all at once pull, because youd only be dealing with a single subscriber? 
    could also kill the subscriber at the end of this function each time.
    """
    def getProperties(self, name, properties):
        # create topic name from model name
        topic_name = "~/" + name +"/scenic_info"
        # create subscriber to named topic (not yet sure if thats the appropriate message type)
        # may need to generate python version of custom gazebo message
        prop_sub   = await self.manager.subscribe(
            topic_name, "scenic_obj_info_msgs", prop_callback
        )
        pass

    def prop_callback(data):
        # a 3d vector containing position coords (X, Y, Z)
        pos    = data.position
        # a quaternion containing the orientation coords (W, X, Y, Z)
        orient = data.orientation
        # a 3d vector containing linear velocity data
        lin    = data.linvelocity
        # a 3d vector containing angular velocity data
        ang    = data.angvelocity

        # format position data
        x = pos.x
        y = pos.y 
        elevation = pos.z 

        # format linear velocity (speed) (drop z, then what?)

        # format angular velocity (only the rotation across z?)

        # format rotation (heading)
        r = R.from_quat(orient)





    # should this be done on init?
    def reset(self):
        pass
    # want a certain time

    # currently steps through simulation 1 iteration (1ms)
    def step():
        # TODO: figure out multistep
        wc_step  = pygazebo.msg.world_control_pb2.WorldControl()
        wc_step.step = True
        await self.world_publisher.publish(wc_step)
        await asyncio.sleep(1)




# clean up:
# getting position per time step
# continuous motion time step
# scenic position + elevation
# quaternian : scipy . rotation
                # rotation across positive z-axis
#  r = R.from_rotvec(np.pi/2 * np.array([0, 0, 1]))
# want that first thing to be obj heading