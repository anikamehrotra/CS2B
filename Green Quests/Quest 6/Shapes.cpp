// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Shapes.h"
using namespace std;

Screen::Screen(size_t w, size_t h) {
    if (w < 1 || h < 1) {return;}
    _pix.resize(h);
    for (size_t i = 0; i < h; i++) {
        _pix[i].resize(w);
    }
    _w = w;
    _h = h;
}

void Screen::fill(char c) {
    for (size_t i = 0; i < _pix.size(); i++) {
        for (size_t j = 0; j < _pix[i].size(); j++) {
            _pix[i][j] = c;
        }
    }
}

string Screen::to_string() const {
    string s;
    for (size_t i = _h; i-- > 0;) {
        for (size_t j = 0; j < _w; j++) {
            s += _pix[i][j];
        }
        s += '\n';
    }
    return s;
}

bool Point::draw(Screen &screen, char c) {
    if (_x < 0 || _x >= screen.get_w() || _y < 0 || _y >= screen.get_h()) {return false;}
    screen.get_pix()[_y][_x] = c;
    return true;
}

// Draw pizels on the screen along the X direction, using the supplied
// char (ch) as the pixel. The number of segments will be abs(y2-y1).
// Each segment will be abs(x2-x1)/abs(y2-y1) pixels long.
bool Line::draw_by_x(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
    if (x1 > x2) return draw_by_x(scr, ch, x2, y2, x1, y1); //reorder
    double dy = ((double) y2-y1)/((double) x2-x1);
    bool contained = true;
    double x = x1, y = y1;
    while (x <= x2) {
        contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
        x++;
        y += dy;
    }
    return contained;
}
bool Line::draw_by_y(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
    if (y1 > y2) return draw_by_y(scr, ch, x2, y2, x1, y1); //reorder)
    double dx = ((double) x2-x1)/((double) y2-y1);
    bool contained = true;
    double x = x1, y = y1;
    while (y <= y2) {
        contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
        x += dx;
        y++;
    }
    return contained;
}

size_t Line::get_height_of_line(size_t x1, size_t y1, size_t x2, size_t y2) {
    int height = y2 - y1; 
    return (size_t) abs(height);
}

size_t Line::get_width_of_line(size_t x1, size_t y1, size_t x2, size_t y2) {
    int width = x2 - x1;
    return (size_t) abs(width);
}

double Line::get_slope(size_t x1, size_t y1, size_t x2, size_t y2) {
    return (double) (y2 - y1) / (double) (x2 - x1);
}

bool Line::draw(Screen &scr, char ch) {
    // if (get_height_of_line(_x1, _y1, _x2, _y2) <= 0 || get_width_of_line(_x1, _y1, _x2, _y2) <= 0) {return false;}
    if (get_height_of_line(_x1, _y1, _x2, _y2) > get_width_of_line(_x1, _y1, _x2, _y2)) 
        {draw_by_y(scr, ch, _x1, _y1, _x2, _y2);} 
    else {draw_by_x(scr, ch, _x1, _y1, _x2, _y2);}
    return true;
}

bool Quadrilateral::draw(Screen &scr, char ch) {
    Line top(_x2, _y2, _x3, _y3);
    Line left(_x1, _y1, _x2, _y2);
    Line right(_x3, _y3, _x4, _y4);
    Line bottom(_x4, _y4, _x1, _y1);

    top.draw(scr, ch);
    left.draw(scr, ch);
    right.draw(scr, ch);
    bottom.draw(scr, ch);

    return true;
}

Stick_Man::Stick_Man(size_t x, size_t y, size_t w, size_t h) {
    _parts.clear();
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    if (h == 0 || h == 1) {_h = DEFAULT_H;}
    if (w == 0 || w == 1) {_w = DEFAULT_W;}
    _parts.push_back(new Upright_Rectangle(_x+0, _y+_h/2, _x+_w-1, _y+_h-1));
    _parts.push_back(new Line(_x+_w/2, _y+_h/2, _x+_w/2,   _y+_h/4));
    _parts.push_back(new Line(_x+_w/2, _y+_h/2, _x+_w/4,   _y+_h/4));
    _parts.push_back(new Line(_x+_w/2, _y+_h/2, _x+3*_w/4, _y+_h/4));
    _parts.push_back(new Line(_x+_w/2, _y+_h/4, _x,        _y));
    _parts.push_back(new Line(_x+_w/2, _y+_h/4, _x+_w-1,   _y));
}

Stick_Man::~Stick_Man() {
    for (size_t i = 0; i < _parts.size(); i++) {
        delete _parts[i];
    }
}

bool Stick_Man::draw(Screen &scr, char ch) {
    for (size_t i = 0; i < _parts.size(); i++) {
        _parts[i]->draw(scr, ch);
    }
    return true;
}
