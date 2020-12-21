#pragma once

#include "WorldEngine.hpp"
#include "Ant.hpp"

class AntBuilder{
    WorldEngine& world_;

public:
    Ant summon(){
        Ant ant(10, 2, 1);
        world_.allAntsInThisWorld_.push_back(ant);
        return ant;
    }

    
    AntBuilder(WorldEngine& world) : world_(world) {}
};