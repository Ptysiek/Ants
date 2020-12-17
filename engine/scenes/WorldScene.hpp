#pragma once


#include <array>
#include <curses.h>
#include <iostream>
#include <string>
#include <vector>

//#include "DisplayMenu.hpp"
#include "../SceneInterface.hpp"
#include "../../tools/Fortuity.hpp"

#include "displays/WorldScene_MainFrame.hpp"
#include "displays/Warning_LittleWindow.hpp"





class WorldScene : public SceneInterface {
    // MainPage_over46x130 ---------------
    Warning_LittleWindow    warn_LittleWindow_;
    WorldScene_MainFrame    ws_MainFrame_;
    
public:

    std::string name() override { return "WorldScene01"; }

    void initDisplays() override {
        clear();
        warn_LittleWindow_.redraw();
        ws_MainFrame_.redraw();
    }

    void drawDisplays() override {
        RenderMainPage();
    }

    bool stallInput() override {
        //int choice = ws_MainFrame_.input();
        int choice = sdInputDisp_.input();


        switch (choice) {
        case KEY_RESIZE:
            initDisplays();
            break;

        case 27:
            MenuEnter("Exit");
        //    ++menu1Big_InputBox_;
            break;

        case KEY_ENTER:
        case 10:    // ENTER
        case 32:    // SPACE
          //  MenuEnter(menu1Big_InputBox_.get_Value());
            break;

        default: 
            return false;
        }
        //ws_MainFrame_.redraw();
        //menu1Big_InputBox_.redraw();
        return true;
    }

private:
    void MenuEnter(std::string input) {

        if (input == "New Game") {
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
      //  menu1Big_InputBox_.rmove(point_x + sceneWidth - menu1Big_InputBox_.get_Width(),
       //                          point_y + sceneHeight - menu1Big_InputBox_.get_Height());

        ws_MainFrame_.refresh();
        //menu1Big_InputBox_.refresh();

    }

    void MainPage_over46x130() {
        ws_MainFrame_.refresh();
       // menu1Big_InputBox_.refresh();
    }

        
    


    void MainPage_lessthen46x130_ArangeItems(int stdHeight, int stdWidth) {
        int point_x, point_y;

        const int sceneWidth = warn_LittleWindow_.get_Width();
        const int sceneHeight = warn_LittleWindow_.get_Height();

        point_x = (stdWidth - sceneWidth) / 2;
        point_y = (stdHeight - sceneHeight) / 2;

        warn_LittleWindow_.mmove(point_x - 2, point_y - 1);

        //ws_MainFrame_.move(point_x, point_y);
        //menu1Big_InputBox_.rmove(point_x + sceneWidth - menu1Big_InputBox_.get_Width(),
        //                         point_y + sceneHeight - menu1Big_InputBox_.get_Height());

        warn_LittleWindow_.refresh();

        //ws_MainFrame_.refresh();

       // menu1Big_Background_.refresh();
        //menu1Big_InputBox_.refresh();

    }

    void MainPage_lessthen46x130() {
        //ws_MainFrame_.refresh();
        //menu1Big_InputBox_/menu1Big_InputBox_.refresh();
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

