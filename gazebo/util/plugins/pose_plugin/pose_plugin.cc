#include "pose_plugin.hh"
#include <iostream>
using namespace gazebo;

// note: have to extend gazebo path to use plugin

void PosePlugin::Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf){
    this->model = _parent;
    this->sdf   = _sdf;
    // listen to update event, which is broadcast every simulation iteration
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&PosePlugin::OnUpdate, this));
    this->node = transport::NodePtr(new transport::Node());

    this->node->Init(this->model->GetWorld()->Name());
    // create topic name
    std::string topicName = "~/" + this->model->GetName()+"/scenic_info";
    // this->pub = this->node->Advertise<msgs::Pose>(topicName);
    this->pub = this->node->Advertise<scenic_obj_info_msgs::msgs::ScenicObjectInfo>(topicName);

}

// function to create and update message containing desired values per simulation iteration
void PosePlugin::OnUpdate () {
    
    // create pose message
    // msgs::Pose model_pose;

    scenic_obj_info_msgs::msgs::ScenicObjectInfo model_pose;
    // create vector3d message to store pose in to match types
    msgs::Vector3d* pv = new gazebo::msgs::Vector3d();
    // create quaternion message to store orientation in to match types
    msgs::Quaternion* oq = new gazebo::msgs::Quaternion();
    // instantiate vector3D, set name and pose fields
    pv->set_x(this->model->WorldPose().Pos().X());
    pv->set_y(this->model->WorldPose().Pos().Y());
    pv->set_z(this->model->WorldPose().Pos().Z());
    std::cout << "name:" << this->model->GetName() << std::endl;
    std::cout << "model pose values: "<< this->model->WorldPose().Pos().X() << "," << this->model->WorldPose().Pos().Y() << "," << this->model->WorldPose().Pos().Z() << std::endl;

    // model_pose.position() = msgs::Convert>(this->model->WorldPose());	
    model_pose.set_name(this->model->GetName());
    model_pose.set_allocated_position(pv);

    // // get orientation values 
    auto rotW = this->model->WorldPose().Rot().W();
    auto rotX = this->model->WorldPose().Rot().X();
    auto rotY = this->model->WorldPose().Rot().Y();
    auto rotZ = this->model->WorldPose().Rot().Z();
    // set orientation values in quaternion
    oq->set_w(rotW);
    oq->set_x(rotX);
    oq->set_y(rotY);
    oq->set_z(rotZ);
    std::cout << "orientation values: "<< rotW << "," << rotX << "," << rotY << "," << rotZ << std::endl;
    // // set orientation field of pose message
    model_pose.set_allocated_orientation(oq);

    // // ---- velocity gathering ----
    msgs::Vector3d* ang  = new gazebo::msgs::Vector3d();
    msgs::Vector3d* lin  = new gazebo::msgs::Vector3d();
    auto linX = this->model->WorldLinearVel().X();
    auto linY = this->model->WorldLinearVel().Y();
    auto linZ = this->model->WorldLinearVel().Z();
    lin->set_x(linX);
    lin->set_y(linY);
    lin->set_z(linZ);
    std::cout << "linear velocity values: "<< linX << "," << linY << "," << linZ << std::endl;
    model_pose.set_allocated_linvelocity(lin);

    auto angX = this->model->WorldAngularVel().X();
    auto angY = this->model->WorldAngularVel().Y();
    auto angZ = this->model->WorldAngularVel().Z();
    ang->set_x(angX);
    ang->set_y(angY);
    ang->set_z(angZ);
    model_pose.set_allocated_angvelocity(ang);
    std::cout << "angular velocity values: "<< angX << "," << angY << "," << angZ << std::endl;
    // publish pose message with update values
    this->pub->Publish(model_pose, true);
    // std::cout << "published!" << std::endl;
    
}