#pragma once


#include "../../i_Display.hpp"

#include <array>




class WorldScene_PauseMenu : public DisplayInterface {

    size_t highlight_;
    std::array<std::string, 2> choices_ = {"Return", "Exit"};



public: 
    // CONSTRUCTOR:
    WorldScene_PauseMenu(): DisplayInterface(45, 20, 4) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);      
        //keypad(window_, true);  
    }



    // `DisplayInterface` OPERATIONS:
    void redraw() override {
        // wclear(window_);

        wresize(window_,scrheight_, scrwidth_);
        keypad(window_, true);

        box(window_, 0, 0); 

        for (size_t i = 0; i < choices_.size(); ++i) {
            if (i == highlight_) {
                wattron(window_, A_REVERSE);
            }
            mvwprintw(window_, static_cast<int>(i+1), 1, (choices_[i]).c_str());
            wattroff(window_, A_REVERSE);
        }    

    }
    void update(int highlight) { update(static_cast<size_t>(highlight)); }
    void update(size_t highlight) { highlight_ = highlight; }


    size_t get_Size() const { return choices_.size(); }
    size_t get_Index() const { return highlight_; }
    std::string get_Value() const { return choices_[highlight_]; }

    size_t operator ++() {
        ++highlight_;

        if (highlight_ >= choices_.size()) {
            highlight_ = 0;
        }
        return highlight_;
    }

    size_t operator --() {
        --highlight_;

        if (highlight_ >= choices_.size()) {
            highlight_ = choices_.size() - 1;
        }
        return highlight_;
    }


};
