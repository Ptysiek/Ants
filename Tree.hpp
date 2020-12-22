#pragma once

#include "Obstacle.hpp"
#include "Info.hpp"

class Tree : public Obstacle {

public:
    Tree() : Obstacle(ObstacleType::TREE) {}
};