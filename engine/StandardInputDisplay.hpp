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
    // void update(int highlight) { update(static_cast<size_t>(highlight)); }
    // void update(size_t highlight) { highlight_ = highlight; }


    // size_t get_Size() const { return choices_.size(); }
    // size_t get_Index() const { return highlight_; }
    // std::string get_Value() const { return choices_[highlight_]; }

    /* 
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
    // */

};
