#pragma once

#include <curses.h>
#include <fstream>
#include <memory>
#include <stack>
#include <string>

#include "Engine.hpp"
#include "i_Scene.hpp"


class Engine_Debug : public Engine {

    std::string logPathFile_ = "lastlog.txt";


public:
    void initStage(std::shared_ptr<i_Scene> scene) override {

        std::fstream save(logPathFile_);
        if (save) {
            save << scene->name();
            throw "sup";
        }
        save.close();

        return Engine::initStage(scene);
    }

protected:
    void gameLoop() override {
        if (scenes_.empty()) {
            return;
        }

        clear();
        auto& scene = scenes_.top();

        scene->init();
        scene->render();

        while(!scene->newcall()) {
            if (scene->input()) {
                scene->render();
            }
        }

        CallProcessing(scene->get_Call());
    }
};

// 18:01