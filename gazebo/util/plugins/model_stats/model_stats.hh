#ifndef _GAZEBO_WORLD_POSE_PLUGIN_HH_
#define _GAZEBO_WORLD_POSE_PLUGIN_HH_
#include <boost/shared_ptr.hpp>
#include <string>
#include <sdf/sdf.hh>
#include <gazebo-11/gazebo/gazebo.hh>
#include <gazebo-11/gazebo/common/common.hh>
#include <gazebo-11/gazebo/physics/physics.hh>
#include <gazebo-11/gazebo/transport/transport.hh>
#include <gazebo-11/gazebo/msgs/msgs.hh>
#include "scenic_obj_info.pb.h"
// #include "scenic_delete_models.pb.h"


namespace gazebo 
{
    // typedef const boost::shared_ptr<const scenic_delete_models_msgs::msgs::ScenicDeleteModels> ScenicDeleteModelsPtr;
    class ModelStats : public WorldPlugin 
    {
        public:
            ModelStats() {}
            void stats(physics::ModelPtr model);
            void virtual Load(physics::WorldPtr world, sdf::ElementPtr _sdf);
            // void callback(ScenicDeleteModelsPtr &_msg);
            void OnUpdate();
            
        
        private:
            // bool gotMsg; 
            physics::WorldPtr world;
            sdf::ElementPtr sdf;
            event::ConnectionPtr updateConnection;
            // event::ConnectionPtr updateConnection;
            // for publishing pose 
            transport::NodePtr node;
            // transport::NodePtr sub;
            transport::PublisherPtr pub;
            // transport::SubscriberPtr sub;
            // boost::shared_ptr<const scenic_delete_models_msgs::msgs::ScenicDeleteModels> message;
            // void OnUpdate();
    };
    // register plugin with simulator
    GZ_REGISTER_WORLD_PLUGIN(ModelStats)
}

#endif