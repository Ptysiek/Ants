#pragma once

#include <curses.h>
#include <memory>
#include <stack>

#include "SceneInterface.hpp"


class Engine {

protected:
    std::stack<std::shared_ptr<SceneInterface>> scenes_;


public:
    virtual void initCurses() final {
        
        //resizeterm(50, 300);
        //wresize(stdscr, 50, 300);

        // [cbreak() / raw()] / [halfdelay(int) / nodelay(win, bool) / timeout(int)]
        //cbreak();
        //raw();   
        halfdelay(1);
        nodelay(stdscr, true);
        // keypad(stdscr, TRUE);

        // [echo() / noecho()]
        noecho();       
        curs_set(0);
        
        ESCDELAY=25;
        
        start_color();  

    }

    virtual void initStage(std::shared_ptr<SceneInterface> scene) {
        scenes_.push(scene);
        gameLoop();
    }


protected:
    virtual void gameLoop() {
        if (scenes_.empty()) {
            return;
        }

        clear();
        auto& scene = scenes_.top();

        scene->init();
        scene->render();

        while(!scene->newcall()) {
            scene->update();
            if (scene->input()) {
                scene->render();
            }
        }

        CallProcessing(scene->get_Call());
    }

    virtual void CallProcessing(std::string call) final {
        if (call.empty()) {
        }
        else if (call == "StackRemove" || call == "Exit") {
            scenes_.pop();
        }


        // gameLoop();
    }



};
