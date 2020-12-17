#pragma once

#include <curses.h>


class DisplayInterface {
protected:
    const int scrwidth_;
    const int scrheight_;
    const int margin_;

    WINDOW* window_ = nullptr;

    DisplayInterface(int startWidth, int startHeight, int startMargin):
        scrwidth_(startWidth),
        scrheight_(startHeight),
        margin_(startMargin) 
    {}

public:
    virtual int get_Xpos() const { return getcurx(window_); }
    virtual int get_Ypos() const { return getcury(window_); }
    virtual int get_Width() const { return getmaxx(window_); }
    virtual int get_Height() const { return getmaxy(window_); }
    virtual int get_IntendedWidth() const { return scrwidth_; }
    virtual int get_IntendedHeight() const { return scrheight_; }
    virtual int get_IntendedMargin() const { return margin_; }

    virtual void redraw() = 0;

    virtual void refresh() { wrefresh(window_); }
    virtual int input() { return wgetch(window_); }

    virtual void mmove(int x, int y) { mvwin(window_, y+(margin_/2), x+margin_); }
    virtual void rmmove(int x, int y) { mvwin(window_, y-(margin_/2), x-margin_); }
    virtual void moveBy(int x, int y) { mvwin(window_, y+get_Ypos(), x+get_Xpos()); }
    virtual void moveTo(int x, int y) { mvwin(window_, y, x); }

    virtual bool correct_size() {
        if (get_Width() != get_IntendedWidth() || get_Height() != get_IntendedHeight()) {
            wresize(window_, get_IntendedHeight(), get_IntendedWidth());
            return true;
        }
        else {
            return false;
        }
    }
};



