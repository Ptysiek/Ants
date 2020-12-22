#pragma once

#include <string>
#include "StandardInputDisplay.hpp"


class SceneInterface {

    bool newcall_;
    std::string call_;


protected:
    StandardInputDisplay sdInputDisp_;
    
    SceneInterface() {
        newcall_ = false;
        call_ = "";
    }

    virtual void initDisplays()=0;
    virtual void drawDisplays()=0;
    virtual bool stallInput()=0;
    virtual void updateLogic()=0;

    void call(std::string call) {
        if (call.empty()) {
            return;
        }

        newcall_ = true;
        call_ = call;
    }

public:
    bool newcall() { 
        if (newcall_) {
            newcall_ = false;
            return true;
        }
        return false; 
    }
    std::string get_Call() const { return call_; }

    virtual std::string name()=0;
    void init() { initDisplays(); }
    void render() { drawDisplays(); }
    bool input() { return stallInput(); }
    void update() { updateLogic(); }
};
