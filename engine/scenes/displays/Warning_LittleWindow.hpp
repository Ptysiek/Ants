#pragma once

#include "../../DisplayInterface.hpp"

#include <array>
#include <string>

class Warning_LittleWindow : public DisplayInterface {


public: // CONSTRUCTOR:
    Warning_LittleWindow(): DisplayInterface(28, 10, 2) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);        
    }

public: // `DisplayInterface` OPERATIONS:
    void redraw() override {
        correct_size();
        wclear(window_);

        box(window_, 0, 0); 

        int stdHeight, stdWidth;
        getmaxyx(stdscr, stdHeight, stdWidth);
        
        mvwprintw(window_, 1, 2, "ERROR_WINDOW_TO_NARROW");
        mvwprintw(window_, 3, 2, "Current Window Size:");
        mvwprintw(window_, 4, 2, "%dx%d", stdWidth, stdHeight);
        mvwprintw(window_, 6, 2, "Expected Window Size:");
        mvwprintw(window_, 7, 2, "%dx%d", 130, 46);
    }
};
