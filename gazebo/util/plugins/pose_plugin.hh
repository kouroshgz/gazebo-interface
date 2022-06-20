#ifndef _GAZEBO_POSE_PLUGIN_HH_
#define _GAZEBO_POSE_PLUGIN_HH_

#include <string>
#include <sdf/sdf.hh>
#include <gazebo-11/gazebo/gazebo.hh>
#include <gazebo-11/gazebo/common/common.hh>
#include <gazebo-11/gazebo/physics/physics.hh>
#include <gazebo-11/gazebo/transport/transport.hh>
#include <gazebo-11/gazebo/msgs/msgs.hh>



namespace gazebo 
{
    class PosePlugin : public ModelPlugin {
        public:
            PosePlugin() {}
            void virtual Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf);
            void OnUpdate();
        
        private:
            physics::ModelPtr model;
            sdf::ElementPtr sdf;
            event::ConnectionPtr updateConnection;
            // for publishing pose 
            transport::NodePtr node;
            // transport::NodePtr sub;
            transport::PublisherPtr pub;
            // transport::SubscriberPtr stats;
    };
    // register plugin with simulator
    GZ_REGISTER_MODEL_PLUGIN(PosePlugin)
}

#endif