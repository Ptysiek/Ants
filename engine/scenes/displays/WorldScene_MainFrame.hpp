#pragma once

#include "../../DisplayInterface.hpp"

#include "../../../WorldEngine.hpp"
#include "../../../AntBuilder.hpp"

class WorldScene_MainFrame : public DisplayInterface {

    WorldEngine world_;
    AntBuilder antBuild_;

public: 
    // CONSTRUCTOR:
    WorldScene_MainFrame(): DisplayInterface(130, 46, 0), antBuild_(world_) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);
        for (size_t i = 0; i < 10; i++)
        {
            antBuild_.summon();
            // ws_MainFrame_.redraw();
            
        } 
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
        for (const auto& ant : world_.allAntsInThisWorld_)
        {
            mvwprintw(window_, ant.getPosY(), ant.getPosX(), "X");
        }
        
    }
};
