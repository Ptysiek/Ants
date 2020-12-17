#pragma once


#include "DisplayInterface.hpp"

#include <array>




class StandardInputDisplay : public DisplayInterface {

public: 
    // CONSTRUCTOR:
    StandardInputDisplay(): DisplayInterface(1, 1, 0) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);      
        keypad(window_, true);  
    }

    // `DisplayInterface` OPERATIONS:
    void redraw() override {
        // wclear(window_);
        // wresize(window_,scrheight_, scrwidth_);
        keypad(window_, true);
    }
};
