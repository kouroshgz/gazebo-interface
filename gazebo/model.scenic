import math
from scenic.simulators.gazebo.simulator import GazeboSimulator

# currently assuming that user launches correct world and gazebo prior to launching scenic    
simulator CarlaSimulator()

class GazeboObject:
    """
        elevation (float or None; dynamic): default ``None``
        requireVisible (bool): Default value ``False`` (overriding the default
            from `Object`).
        modelName (str): 'DEF' name of the gazebo model to use for this object.
        modelSDF(str): 'DEF' the sdf string containing the specification of the model
        pose (3D Vector): coordinates of current position 
            - can be placed inline in SDF string or specified separately
            - if specified separately, ensure that SDF string doesnt have pose values specified
        orientation (Quaternion): orientation of the model, same specification rules as pose
    """
    elevation[dynamic]: None
    requireVisible: False
    modelName: None
    modelSDF: None
    orientation: None
    pose: None
    