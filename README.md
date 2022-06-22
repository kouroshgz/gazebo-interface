# gazebo-interface

Work on interface between Scenic programming language and Gazebo open source robotics simulator. 

Notes:
- requires protobuf-compiler as a dependency package
  * sudo apt-get install protobuf-compiler
- build by calling cmake ../ from within the plugin build folder
- need to extend gazebo plugin path with path to this plugin or copy plugin to your plugin directory
  * export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH=$PWD:$GAZEBO_PLUGIN_PATH
  * sudo cp pose_plugin.so /usr/lib/gazebo-<GAZEBO_VERSION>/plugins/

Note: only tested on Gazebo 11. 
