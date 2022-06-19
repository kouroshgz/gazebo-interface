#include "pose_plugin.hh"
// #include <ignition/math6/ignition/math/Quaternion.hh>
// #include <ignition/math6/ignition/math/Vector3.hh>
using namespace gazebo;

void PosePlugin::Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf){
    this->model = _parent;
    this->sdf   = _sdf;
    // listen to update event, which is broadcast every simulation iteration (is that the same thing as a step?)
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&PosePlugin::OnUpdate, this));

    this->node = transport::NodePtr(new transport::Node());
    this->node->Init(this->model->GetWorld()->Name());
    // create topic name
    std::string topicName = "~/" + this->model->GetName()+"/pose_info";
    // Sub to topic, register callback
    this->node->Advertise<msgs::Model>(topicName);
    // this->pub = posePub;

    // can also get all the velocities, should look into creating custom message that contains all this and just publish to one topic
    // would remove need for an IMU potentially

}

// function to create and update message containing desired values per simulation iteration
void PosePlugin::OnUpdate () {
    // create pose message
    msgs::Pose model_pose;
    // create vector3d message to store pose in to match types
    msgs::Vector3d pv;
    // create quaternion message to store orientation in to match types
    msgs::Quaternion oq;
    // instantiate vector3D, set name and pose fields
    pv.set_x(this->model->WorldPose().Pos().X());
    pv.set_y(this->model->WorldPose().Pos().Y());
    pv.set_z(this->model->WorldPose().Pos().Z());
    model_pose.set_name(this->model->GetName());
    model_pose.set_allocated_position(&pv);

    // get orientation values 
    auto rotW = this->model->WorldPose().Rot().W();
    auto rotX = this->model->WorldPose().Rot().X();
    auto rotY = this->model->WorldPose().Rot().Y();
    auto rotZ = this->model->WorldPose().Rot().Z();
    // set orientation values in quaternion
    oq.set_w(rotW);
    oq.set_x(rotX);
    oq.set_y(rotY);
    oq.set_z(rotZ);
    // set orientation field of pose message
    model_pose.set_allocated_orientation(&oq);
    // publish pose message with update values
    this->pub->Publish(model_pose);
}