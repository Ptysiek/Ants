#include <iostream>
#include <vector>
#include <algorithm>

#include "Ant.hpp"
#include "Info.hpp"
#include "WorldMatrix.hpp"
#include "WorldEngine.hpp"
#include "engine/Engine.hpp"

// #include "engine/scenes/WorldScene.hpp"

int main() {

    Engine program;

    initscr();
    program.initCurses();
    // program.initStage(std::make_shared<WorldScene>());
    endwin();

    return 0;





    WorldEngine world;
    
    TaskInformations taskInfo;
    taskInfo.taskGrade.push_back(TaskPriority::thirst);
    taskInfo.taskGrade.push_back(TaskPriority::defend_base);
    taskInfo.taskGrade.push_back(TaskPriority::collect_food);
    taskInfo.taskGrade.push_back(TaskPriority::thirst);
    taskInfo.taskGrade.push_back(TaskPriority::hunger);
    
    for (const auto& record : taskInfo.taskGrade) {
        std::cout << record << "\n";
    }
    
    std::sort(taskInfo.taskGrade.begin(), taskInfo.taskGrade.end());
    
    std::cout << "\n\n";
    
    for (const auto& record : taskInfo.taskGrade) {
        std::cout << record << "\n";
    }    
    
    return 0;
}

