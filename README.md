# gazebo-interface

Work on interface between Scenic programming language and Gazebo open source robotics simulator. 
This is not production/pr/official code in any way, just a scratchpad to organize work. 

Notes:
(These will be turned into proper documentation when ready for release)
- Plugin build instructions:
- requires protobuf-compiler as a dependency package
  * sudo apt-get install protobuf-compiler
- build by calling cmake ../ from within the plugin build folder
- need to extend gazebo plugin path with path to this plugin or copy plugin to your plugin directory
  * export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH=$PWD:$GAZEBO_PLUGIN_PATH
  * sudo cp pose_plugin.so /usr/lib/gazebo-<GAZEBO_VERSION>/plugins/

- Simulator Notes:
- creating multiple instances of a gazebo simulator object in the same environment will break functionality due to global event loop mismatch
- all world files must first be prepped with the utility script found in /util
- must build all required plugins 
- models currently found via regex match on the word "scenic" in model name, will change to something more unique soon

Note: only tested on Gazebo 11. Due to minor changes in API calls, prior versions of gazebo classic will require minor edits to the code for the required plugins.
