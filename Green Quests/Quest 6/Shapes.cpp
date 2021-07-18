// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Shapes.h"

Screen::Screen(size_t w, size_t h) {
    _pix.resize(h);
    _pix[h].resize(w);
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
    for (size_t i = _h-1; i >= 0; i--) {
        for (size_t j = 0; j < _w; j++) {
            s += _pix[i][j];
        }
        s += '\n';
    }
    return s;
}

using namespace std;