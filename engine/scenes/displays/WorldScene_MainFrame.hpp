#pragma once

#include "../../DisplayInterface.hpp"
#include "../WorldSceneLogic.hpp"


class WorldScene_MainFrame : public DisplayInterface {

    // EXTRA INSIDE SCENE LOGIC --------------------------------------
    WorldSceneLogic& worldEngineLogic_;


public: 
    // CONSTRUCTOR:
    WorldScene_MainFrame(WorldSceneLogic& wsl) : 
        DisplayInterface(130, 46, 0),
        worldEngineLogic_(wsl)
    {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);
    }

    // `DisplayInterface` OPERATIONS:
    void redraw() override {
        wresize(window_,scrheight_, scrwidth_);
        // keypad(window_, true);
        wclear(window_);
        wattron(window_, A_DIM); 
        box(window_, 0, 0);
        wattroff(window_, A_DIM);
        //refresh();
        // wrefresh(window_);
        // mvwprintw(window_, world_.allAntsInThisWorld_[0].getPosY(), world_.allAntsInThisWorld_[0].getPosX(), "X");
        for (const auto& ant : worldEngineLogic_.world_.allAntsInThisWorld_)
        {
            mvwprintw(window_, ant.getPosY(), ant.getPosX(), "X");
        }
        
    }
};
