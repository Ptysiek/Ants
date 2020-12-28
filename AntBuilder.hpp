#pragma once

#include "WorldEngine.hpp"
#include "Ant.hpp"

class AntBuilder{
    WorldEngine& world_;

public:
    WorldAnt summon(){
        WorldAnt newAnt {
            Ant(10,2,1),
            Fortuity::getRandom(1, 128),
            Fortuity::getRandom(1, 44)
        };
        world_.allAntsInThisWorld_.push_back(newAnt);
        return newAnt;
    }

    
    AntBuilder(WorldEngine& world) : world_(world) {}
};
