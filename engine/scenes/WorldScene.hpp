#pragma once


#include <array>
#include <curses.h>
#include <iostream>
#include <string>
#include <vector>


#include "../SceneInterface.hpp"
#include "../../tools/Fortuity.hpp"

#include "displays/WorldScene_MainFrame.hpp"
#include "displays/Warning_LittleWindow.hpp"
#include "displays/WorldScene_PauseMenu.hpp"



class WorldScene : public SceneInterface {
    // MainPage_lessthen46x130 -----------
    Warning_LittleWindow    warn_LittleWindow_;
    // MainPage_over46x130 ---------------
    WorldScene_MainFrame    ws_MainFrame_;
    // FastMenuPage_allsize --------------
    WorldScene_PauseMenu    ws_PauseMenu_;
    
public:
    std::string name() override { return "WorldScene01"; }
    void initDisplays() override {
        clear();
        warn_LittleWindow_.redraw();
        ws_MainFrame_.redraw();
        ws_PauseMenu_.redraw();
    }
    void drawDisplays() override { RenderMainPage(); }
    bool stallInput() override { return stallInput(sdInputDisp_.input()); }

    bool stallInput(int choice) {
        switch (choice) {
        case KEY_RESIZE:
            initDisplays();
            break;
        
        case 'K':
        case 'k':
        case 'W':
        case 'w':
            --ws_PauseMenu_;
            break;
        
        case 'J':
        case 'j':
        case 'S':
        case 's':
            ++ws_PauseMenu_;
            break;

        case 'q':
        case 'Q':
        case 27:    // ESCAPE
            ws_PauseMenu_.toggleVisibility();   
            ws_MainFrame_.refresh();
            break;

        case KEY_ENTER:
        case 10:    // ENTER
        case 32:    // SPACE
            MenuEnter(ws_PauseMenu_.get_Value());
            break;

        default: 
            return false;
        }
        ws_PauseMenu_.redraw();
        return true;
    }

private:
    void MenuEnter(std::string input) {

        if (input == "Resume") {
            ws_PauseMenu_.toggleVisibility(false);
            // stack new scene
            // scenes.push(scene);
            // call()
        }
        else if (input == "Exit") {
            // remove this scene from stack
            call("StackRemove");
    
        }
    }


    void MainPage_over46x130_ArangeItems(int stdHeight, int stdWidth) {
        int point_x, point_y;

        const int sceneWidth = ws_MainFrame_.get_Width();
        const int sceneHeight = ws_MainFrame_.get_Height();

        point_x = (stdWidth - sceneWidth) / 2;
        point_y = (stdHeight - sceneHeight) / 2;

        ws_MainFrame_.mmove(point_x, point_y);
        ws_PauseMenu_.mmove(point_x, point_y);

        ws_MainFrame_.refresh();
        ws_PauseMenu_.refresh();
    }

    void MainPage_over46x130() {
        ws_MainFrame_.refresh();
        ws_PauseMenu_.refresh();
    }

    void MainPage_lessthen46x130_ArangeItems(int stdHeight, int stdWidth) {
        int point_x, point_y;

        const int sceneWidth = warn_LittleWindow_.get_Width();
        const int sceneHeight = warn_LittleWindow_.get_Height();

        point_x = (stdWidth - sceneWidth) / 2;
        point_y = (stdHeight - sceneHeight) / 2;

        warn_LittleWindow_.mmove(point_x - 2, point_y - 1);
        
        warn_LittleWindow_.refresh();
    }

    void MainPage_lessthen46x130() {
        warn_LittleWindow_.refresh();
    }

    void RenderMainPage() {       
        int stdHeight, stdWidth;
        getmaxyx(stdscr, stdHeight, stdWidth);
        // clear();
        refresh();

        if (stdHeight >= 46 && stdWidth >= 130) {
           // clear();
            MainPage_over46x130_ArangeItems(stdHeight, stdWidth);
            MainPage_over46x130();
        }
        else {
           // clear();
            MainPage_lessthen46x130_ArangeItems(stdHeight, stdWidth);
            MainPage_lessthen46x130();
        }
    }
};







