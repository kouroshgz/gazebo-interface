model scenic.simulators.gazebo.model
workspace = Workspace(RectangularRegion((0, 0), 0, 50, 50))
class Box(GazeboObject):
    name: 'scenicbox'
    modelSDF:  """<?xml version='1.0'?>
        <sdf version ='1.5'>
          <model name ='scenicegobox'>
            <pose>1 2 0 0 0 0</pose>
            <link name ='link'>
              <pose>0 0 .5 0 0 0</pose>
              <collision name ='collision'>
                <geometry>
                  <box><size>1 1 1</size></box>
                </geometry>
              </collision>
              <visual name ='visual'>
                <geometry>
                  <box><size>1 1 1</size></box>
                </geometry>
              </visual>
                         <sensor name="imu_sensor" type="imu">
                                <always_on>true</always_on>
                                <update_rate>100</update_rate>
                                <visualize>true</visualize>
                                <topic>imu/data</topic>
                                        <topicName>imu</topicName>
                                        <bodyName>imu_link</bodyName>
                                        <updateRateHZ>10.0</updateRateHZ>
                                        <gaussianNoise>0.0</gaussianNoise>
                                        <xyzOffset>0 0 0</xyzOffset>
                                        <rpyOffset>0 0 0</rpyOffset>
                                        <frameName>imu_link</frameName>
                                        <initialOrientationAsReference>false</initialOrientationAsReference>
                                <pose>0 0 0 0 0 0</pose>
                        </sensor>
            </link>
           <plugin name="pose_plugin" filename="libpose_plugin.so"/>
          </model>
        </sdf>"""
    width: 0.1
    length: 0.1

class NotEgoBox(GazeboObject):
    name: 'scenicnotegobox'
    modelSDF:  """<?xml version='1.0'?>
        <sdf version ='1.5'>
          <model name ='scenicnotegobox'>
            <pose>1 2 0 0 0 0</pose>
            <link name ='link'>
              <pose>0 0 .5 0 0 0</pose>
              <collision name ='collision'>
                <geometry>
                  <box><size>1 1 1</size></box>
                </geometry>
              </collision>
              <visual name ='visual'>
                <geometry>
                  <box><size>1 1 1</size></box>
                </geometry>
              </visual>
                         <sensor name="imu_sensor" type="imu">
                                <always_on>true</always_on>
                                <update_rate>100</update_rate>
                                <visualize>true</visualize>
                                <topic>imu/data</topic>
                                        <topicName>imu</topicName>
                                        <bodyName>imu_link</bodyName>
                                        <updateRateHZ>10.0</updateRateHZ>
                                        <gaussianNoise>0.0</gaussianNoise>
                                        <xyzOffset>0 0 0</xyzOffset>
                                        <rpyOffset>0 0 0</rpyOffset>
                                        <frameName>imu_link</frameName>
                                        <initialOrientationAsReference>false</initialOrientationAsReference>
                                <pose>0 0 0 0 0 0</pose>
                        </sensor>
            </link>
           <plugin name="pose_plugin" filename="libpose_plugin.so"/>
          </model>
        </sdf>"""
    width: 0.1
    length: 0.1
ego = Box

NotEgoBox in workspace
NotEgoBox in workspace
NotEgoBox in workspace
terminate after 2