#pragma once


#include "../../DisplayInterface.hpp"


class WorldScene_MainFrame : public DisplayInterface {

public: 
    // CONSTRUCTOR:
    WorldScene_MainFrame(): DisplayInterface(130, 46, 0) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);    
        keypad(window_, true);
    }

    // `DisplayInterface` OPERATIONS:
    void redraw() override {
        wresize(window_,scrheight_, scrwidth_);
        keypad(window_, true);
        wclear(window_);
        wattron(window_, A_DIM); 
        box(window_, 0, 0);
        wattroff(window_, A_DIM);
        //refresh();
        // wrefresh(window_);
    }
};
