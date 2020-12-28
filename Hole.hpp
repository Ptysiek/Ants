#pragma once

#include "Obstacle.hpp"
#include "Info.hpp"

class Hole : public Obstacle {

public:
    Hole() : Obstacle(ObstacleType::HOLE) {
        sign_ = 'O';
    }
};