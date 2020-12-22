#pragma once

#include <tuple>
#include <vector>

// -----------------------------------------------------------------------------
enum Infotype {
    got_food,
    enemy,
    colony,
    task
};

enum ObstacleType{
    TREE,
    ROCK,
    HOLE
};

class Info {
    int lifespan_;
    Infotype infotype_;
    size_t posX_, posY_;
    size_t quantity_;
    
public:
    std::tuple<Infotype, size_t, size_t, size_t> getinfo() {
        --lifespan_;
        return std::make_tuple(infotype_, posX_, posY_, quantity_);
    }
};

struct AntInformations {
    size_t antId_;
    std::vector<Info> informations_;    
};

struct TileInformations {
    char whatGround_;
    std::vector<Info> informations_;
};


enum TaskPriority{
    thirst,
    defend_base,
    collect_food,
    hunger,
    build_strength,
    make_babies,
    attack_base
};

struct TaskInformations{
    TaskPriority task;
    std::vector<TaskPriority> taskGrade;
};