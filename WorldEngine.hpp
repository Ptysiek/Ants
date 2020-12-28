#pragma once

#include <vector>


#include "WorldMatrix.hpp"
#include "Ant.hpp"




struct WorldAnt : public Ant {
    int x_pos;
    int y_pos;
};



class WorldEngine {
// private:
 
public:
    WorldMatrix matrix_;
    std::vector<WorldAnt> allAntsInThisWorld_;

    // 0 - dirt
    // 1 - grass
    // 2 - rock
    // # - water
    // * - food
    // @ - base
    // + - path


};
