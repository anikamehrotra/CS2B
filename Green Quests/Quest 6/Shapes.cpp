// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Shapes.h"

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
    screen.get_pix()[_x][_y] = c;
    return true;
}

// Draw pizels on the screen along the X direction, using the supplied
// char (ch) as the pixel. The number of segments will be abs(y2-y1).
// Each segment will be abs(x2-x1)/abs(y2-y1) pixels long.
static bool draw_by_x(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
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
static bool draw_by_y(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2) {
    if (y1 > y2) return draw_by_y(scr, ch, x2, y2, x1, y1); //reorder)
    double dx = ((double) x2-x1)/((double) y2-y1);
    bool contained = true;
    double x = x1, y = y1;
    while (y <= y2) {
        contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
        x += dx;
        y++;
    }
}

bool Line::draw(Screen &scr, char ch = Screen::FG) {
    if (_x2 - _x1 > _y2 - _y1) {
        
    }

}

using namespace std;