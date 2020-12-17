#pragma once

#include <vector>


#include "WorldMatrix.hpp"
#include "Ant.hpp"


class WorldEngine {
// private:
    WorldMatrix matrix_;
    
    std::vector<Ant> allAntsInThisWorld_;


    // 0 - dirt
    // 1 - grass
    // 2 - rock
    // # - water
    // * - food
    // @ - base
    // + - path
};
