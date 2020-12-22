#pragma once

#include "tools/Fortuity.hpp"

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

    std::pair<int,int> targetPos_;
    
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
        defense_(defense),
        posX_(Fortuity::getRandom(1, 125)),
        posY_(Fortuity::getRandom(1, 50)),
        targetPos_(std::pair<int,int>(Fortuity::getRandom(1,125), Fortuity::getRandom(1,50)))
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

    int getPosX() const { return posX_;}
    int getPosY() const { return posY_;}
    
    void behave() {
        // for(auto& task : priority_) {
        goTo();    
        // }
    }
    void goTo() {
        const auto& [posx, posy] = targetPos_;

        if (posx == posX_ && posy == posY_) {
            std::pair<int,int> newTarget(Fortuity::getRandom(10, 100), Fortuity::getRandom(5, 35));
            setTargetPos(newTarget);
        }
        else {
            moveCoordinate(posx, posX_);
            moveCoordinate(posy, posY_);
        }
    }

    void moveCoordinate(const int& pos, int& pos_) {
        int dir = 0;
        
        if (pos > pos_) {
            dir = 1; 
        } 
        else if (pos < pos_) {
            dir = -1;
        }
        pos_ += dir;
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
