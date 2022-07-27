from scenic.simulators.gazebo.simulator import GazeboSimulator

# currently assuming that user launches correct world and gazebo prior to launching scenic    
simulator GazeboSimulator()

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

        Note 7/20/22:
            - Orientation: defaulted to Vector to deal with type issues in simulator.py
            - added linVelocity and angVelocity, these are fields in the protobuff message used in the plugins, 
              not including them here leads to "object doesnt have attr" errors
    """
    elevation[dynamic]: None
    requireVisible: False
    name: None
    modelSDF: None
    orientation: Vector
    pose: None
    linVelocity: Vector 
    angVelocity: Vector
    