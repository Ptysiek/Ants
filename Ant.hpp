#pragma once

#include <vector>

#include "tools/Fortuity.hpp"

#include "Info.hpp"
#include "WorldMatrix.hpp"

// -----------------------------------------------------------------------------
class Ant {
    size_t id_;
    static size_t s_idCounter;
    
    bool dead_;
    int maxLifespan_;
    int lifespan_ = maxLifespan_;
    int attack_, defense_;

    std::pair<int,int> targetPos_;
    
    // Statuses
    int maxHunger_, maxThirst_, maxStrength_;
    int hunger_, thirst_, strength_;
    
    std::vector<AntInformations> knowledge_;
    
    std::vector<TaskPriority> priority_;
    
    std::vector<std::pair<size_t,size_t>> whereIwas_;
    

public:
    Ant(int lifespan, int attack, int defense):
        dead_(false),
        lifespan_(lifespan),
        attack_(attack), 
        defense_(defense),
        targetPos_(std::pair<int,int>(Fortuity::getRandom(1,128), Fortuity::getRandom(1,44)))
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

   // int getPosX() const { return posX_;}
   // int getPosY() const { return posY_;}
    
    std::string behave(WorldScope worldScope) {
        std::string decision;
        // for(auto& task : priority_) {
        goTo();    
        
        whereIwas_.push_back(std::pair<size_t,size_t>(worldScope.x, worldScope.y));
        
        int rand = Fortuity::getRandom(0,3);
        switch (rand) {
        case 0:
            decision = "goDOWN";    
            break;
        case 1:
            decision = "goLEFT";    
            break;
        case 2:
            decision = "goRIGHT";    
            break;
        default:
            decision = "goUP";    
        }

        return decision;
    }
    void goTo() {
    /*
        const auto& [posx, posy] = targetPos_;

        if (posx == posX_ && posy == posY_) {
            std::pair<int,int> newTarget(Fortuity::getRandom(1, 128), Fortuity::getRandom(1, 44));
            setTargetPos(newTarget);
        }
        else {
            moveCoordinate(posx, posX_);
            moveCoordinate(posy, posY_);
        }*/
    }

    void moveCoordinate(const int& pos, int& pos_) {
        int dir = 0;
        //*
        if (pos > pos_) {
            dir = 1; 
        } 
        else if (pos < pos_) {
            dir = -1;
        }
        pos_ += dir; 
        //*/
    }


    // Setters
    void setHunger(int hunger) { hunger_ = hunger; }
    void setThirst(int thirst) { thirst_ = thirst; }
    void setStrength(int strength) { strength_ = strength; }

private:
    void setTargetPos(std::pair<int,int> targetPos) { targetPos_ = targetPos; } 
    
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
