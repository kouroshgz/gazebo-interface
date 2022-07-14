#include "delete_models.hh"
#include <regex.h>
#include <iostream>
using namespace gazebo;
// NOTE: need to advertise topic separately through pygazebo
void DeleteModels::Load(physics::WorldPtr world, sdf::ElementPtr _sdf){
    this->world = world;
    this->sdf   = sdf;
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&DeleteModels::OnUpdate, this));
    std::cout << "in load in delete_models" << std::endl;
    this->node  = transport::NodePtr(new transport::Node());
    this->node->Init(this->world->Name());
    // std::string topicName = "~/" + this->world->Name()+"/scenic_delete_models";
    std::string topicName = "~/scenic_delete_models";
    // this->pub = this->node->Advertise<scenic_delete_models_msgs::msgs::ScenicDeleteModels>(topicName);
    this->sub = this->node->Subscribe(topicName, &DeleteModels::callback, this);    
    this->gotMsg = false;
    
}

void DeleteModels::callback(ScenicDeleteModelsPtr &_msg){
    std::cout << "in callback in delete plugin" << std::endl; 
    this->message = _msg;
    this->gotMsg = true;


    // if (_msg->clearall()){
    //     // get vector of all models in world
    //     gazebo::physics::Model_V v = this->world->Models();
    //     // do a regex match on the word scenic (idea is to prepend this to the name of each dynamically created object)
    //     std::regex re ("scenic");
    //     // remove all models whose name begins with "scenic"
        
    //     for (auto e : v) {
    //         std::cout << "current model: " << e->GetName() << std::endl;
    //         if (std::regex_search(e->GetName(), re)) {
    //             std::cout << "in regex if" << std::endl;
    //             this->world->RemoveModel(e->GetName());
    //         }
    //     }
    //     std::cout << "done delete loop" << std::endl;
    //     // idea is to iterate through the vector and delete all models matching a criteria that will 
    //     // only apply to dynamically created models. 
    //     this->world->ClearModels();
    //     this->world->Reset();
    // }
    // else if (!(_msg->clearall()) && !(_msg->name().empty())) {
    //     this->world->RemoveModel(_msg->name());
    // }

    // if (_msg->reset()) {
    //     this->world->Reset();
    // }
    
    return;
}

void DeleteModels::OnUpdate(){
    // std::cout << "onupdate() " << std::endl;
    // auto _msg = this->message; 
    if (this->gotMsg) {
        auto _msg = this->message; 
        std::cout << "gotMsge == 1 " << std::endl;
        if (_msg->clearall()){
        // get vector of all models in world
        gazebo::physics::Model_V v = this->world->Models();
        // do a regex match on the word scenic (idea is to prepend this to the name of each dynamically created object)
        std::regex re ("scenic");
        // remove all models whose name begins with "scenic"
        
        for (auto e : v) {
            std::cout << "current model: " << e->GetName() << std::endl;
            if (std::regex_search(e->GetName(), re)) {
                std::cout << "in regex if" << std::endl;
                this->world->RemoveModel(e->GetName());
            }
        }
        std::cout << "done delete loop" << std::endl;
        // idea is to iterate through the vector and delete all models matching a criteria that will 
        // only apply to dynamically created models. 
        // this->world->ClearModels();
        this->world->Reset();
        }
        else if (!(_msg->clearall()) && !(_msg->name().empty())) {
            this->world->RemoveModel(_msg->name());
        }

        if (_msg->reset()) {
            this->world->Reset();
        }

        this->gotMsg = false;
    }
    return;
}