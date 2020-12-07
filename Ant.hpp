#pragma once

#include "Info.hpp"


// -----------------------------------------------------------------------------
class Ant {
    size_t id_;
    static size_t s_idCounter;
    
    bool dead_;
    int maxLifespan_;
    int lifespan_ = maxLifespan_;
    int attack_, defense_;
    int posX_, posY_;
    
    // Statuses
    int maxHunger_, maxThirst_, maxStrength_;
    int hunger_, thirst_, strength_;
    
    std::vector<AntInformations> knowledge_;
    
    std::vector<TaskPriority> priority_;
    
public:
    Ant(int lifespan, int attack, int defense):
        dead_(false),
        lifespan_(lifespan),
        attack_(attack), 
        defense_(defense) 
    {
        id_ = ++s_idCounter; 
    }
    

    // Getters
    void getHit(int dmg) {
        if (dmg < defense_) {
            return;
        }
        
        lifespan_ -= (dmg - defense_);   
        
        if (lifespan_ <= 0) {
            dead_ = true;
        }
    }
    
    void currentDoin() {
        // for(auto& task : priority_) {
            
        // }
    }
    
    // Setters
    void setHunger(int hunger) { hunger_ = hunger; }
    void setThirst(int thirst) { thirst_ = thirst; }
    void setStrength(int strength) { strength_ = strength; }

private:
    // Operations
    void attack(Ant& ant){
        ant.getHit(attack_);
        //ant.hit(attack_);
    }
    
    void collectFood(){
        hunger_ += 2;
        if (lifespan_ > maxLifespan_){
            attack_ += 1;
            return;
        }
        lifespan_ += 1;
    }
    
    void collectWater(){
        thirst_ += 1;
    }
    
};
size_t Ant::s_idCounter = 0;
