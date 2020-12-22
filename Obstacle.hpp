#pragma once

#include "Info.hpp"

class Obstacle{
private:
    size_t id_;
    static size_t s_idCounter;
    const int type_;

public:
    Obstacle(int type) : type_(type){} 
    virtual int get_id() const {return id_;}
    virtual int get_type() const {return type_;}

    virtual void action() = 0;
};
size_t Obstacle::s_idCounter = 0;