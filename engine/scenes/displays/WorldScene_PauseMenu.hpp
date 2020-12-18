#pragma once


#include "../../DisplayInterface.hpp"

#include <array>




class WorldScene_PauseMenu : public DisplayInterface {

    size_t highlight_;
    std::array<std::string, 2> choices_ = {"Resume", "Exit"};

    bool visible_ = false;

public: 
    // CONSTRUCTOR:
    WorldScene_PauseMenu(): DisplayInterface(45, 20, 4) {
        window_ = newwin(scrheight_, scrwidth_, margin_/2, margin_);      
    }

    void toggleVisibility() { visible_ = !visible_; }
    void toggleVisibility(bool state) { visible_ = state; }
    
    bool get_Visibility() const { return visible_; }

    // `DisplayInterface` OPERATIONS:
    void redraw() override {
        if (!visible_) {
            this->clear();
            return;
        }

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
    
    std::string get_Value() const { 
        if (!visible_) {
            return "none";
        }
        return choices_[highlight_]; 
    }

    size_t operator ++() {
        if (!visible_) {
            return highlight_;
        }
        ++highlight_;

        if (highlight_ >= choices_.size()) {
            highlight_ = 0;
        }
        return highlight_;
    }

    size_t operator --() {
        if (!visible_) {
            return highlight_;
        }
        --highlight_;

        if (highlight_ >= choices_.size()) {
            highlight_ = choices_.size() - 1;
        }
        return highlight_;
    }
};





