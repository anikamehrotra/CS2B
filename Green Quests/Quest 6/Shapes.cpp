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
    vector<vector<char> > pix = screen.get_pix();
    pix[_x][_y] = c;
    return true;
}

using namespace std;