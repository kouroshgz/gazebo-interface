#include "model_stats.hh"
#include <iostream>
using namespace gazebo;

// note: have to extend gazebo path to use plugin

void ModelStats::Load(physics::WorldPtr world, sdf::ElementPtr _sdf){
    std::cout<<"in model_stats load"<<std::endl;
    this->world = world;
    this->sdf   = _sdf;
    // listen to update event, which is broadcast every simulation iteration
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&ModelStats::OnUpdate, this));
    this->node = transport::NodePtr(new transport::Node());

    this->node->Init(this->world->Name());
    // create topic name
    std::string topicName = "~/scenic_model_stats";
    // this->pub = this->node->Advertise<msgs::Pose>(topicName);
    this->pub = this->node->Advertise<scenic_obj_info_msgs::msgs::ScenicObjectInfo>(topicName);

}

void ModelStats::OnUpdate() {
    gazebo::physics::Model_V v = this->world->Models();
    std::regex re ("scenic");
     for (auto e : v) {
            // std::cout << "current model: " << e->GetName() << std::endl;
            if (std::regex_search(e->GetName(), re)) {
                stats(e);
            }
        }
    return;
}

void ModelStats::stats(physics::ModelPtr model) {
    scenic_obj_info_msgs::msgs::ScenicObjectInfo model_pose;
    // create vector3d message to store pose in to match types
    msgs::Vector3d* pv = new gazebo::msgs::Vector3d();
    // create quaternion message to store orientation in to match types
    msgs::Quaternion* oq = new gazebo::msgs::Quaternion();
    // instantiate vector3D, set name and pose fields
    pv->set_x(model->WorldPose().Pos().X());
    pv->set_y(model->WorldPose().Pos().Y());
    pv->set_z(model->WorldPose().Pos().Z());
    std::cout << "---------------- name:" << model->GetName() << " ----------------------" << std::endl;
    // std::cout << "model pose values: "<< model->WorldPose().Pos().X() << "," << model->WorldPose().Pos().Y() << "," << model->WorldPose().Pos().Z() << std::endl;

    // model_pose.position() = msgs::Convert>(this->model->WorldPose());	
    model_pose.set_name(model->GetName());
    model_pose.set_allocated_position(pv);

    // // get orientation values 
    auto rotW = model->WorldPose().Rot().W();
    auto rotX = model->WorldPose().Rot().X();
    auto rotY = model->WorldPose().Rot().Y();
    auto rotZ = model->WorldPose().Rot().Z();
    // set orientation values in quaternion
    oq->set_w(rotW);
    oq->set_x(rotX);
    oq->set_y(rotY);
    oq->set_z(rotZ);
    // std::cout << "orientation values: "<< rotW << "," << rotX << "," << rotY << "," << rotZ << std::endl;
    // // set orientation field of pose message
    model_pose.set_allocated_orientation(oq);

    // // ---- velocity gathering ----
    msgs::Vector3d* ang  = new gazebo::msgs::Vector3d();
    msgs::Vector3d* lin  = new gazebo::msgs::Vector3d();
    auto linX = model->WorldLinearVel().X();
    auto linY = model->WorldLinearVel().Y();
    auto linZ = model->WorldLinearVel().Z();
    lin->set_x(linX);
    lin->set_y(linY);
    lin->set_z(linZ);
    // std::cout << "linear velocity values: "<< linX << "," << linY << "," << linZ << std::endl;
    model_pose.set_allocated_linvelocity(lin);

    auto angX = model->WorldAngularVel().X();
    auto angY = model->WorldAngularVel().Y();
    auto angZ = model->WorldAngularVel().Z();
    ang->set_x(angX);
    ang->set_y(angY);
    ang->set_z(angZ);
    model_pose.set_allocated_angvelocity(ang);
    // std::cout << "angular velocity values: "<< angX << "," << angY << "," << angZ << std::endl;
    // publish pose message with update values
    this->pub->Publish(model_pose, false);
    // std::cout << "published!" << std::endl;
}
