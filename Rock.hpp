#pragma once

#include "Obstacle.hpp"
#include "Info.hpp"

class Rock : public Obstacle {
private:
    int hardLevel;
public:
    Rock() : Obstacle(ObstacleType::ROCK) {
        sign_ = 'R';
    }
};