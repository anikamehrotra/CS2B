// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#include "Graph.h"
using namespace std;

void Graph::make_silly_snake() {
    _nodes.clear();
    add_edge(0, 1, "i-see");
    add_edge(1, 2, "the-silly-snake");
    add_edge(2, 3, "i-be");
    add_edge(3, 4, "you-saw-me");
    add_edge(4, 5, "once-like");
    add_edge(5, 0, "kekule");
};

void Graph::make_mr_sticky() {
    _nodes.clear();
    add_edge(0, 1, ".");
    add_edge(1, 2, ".");
    add_edge(1, 3, ".");
    add_edge(1, 4, ".");
    add_edge(4, 5, ".");
    add_edge(4, 6, ".");
};

void Graph::make_driftin_dragonfly() {
    _nodes.clear();
    add_edge(0, 1, "dis-be-me-head");
    add_edge(1, 2, "me");
    add_edge(2, 3, "long-tail");
    add_edge(3, 4, "be-dis");

    add_edge(1, 5, "dis-be-me");
    add_edge(5, 6, "front-right");
    add_edge(6, 7, "me-right");
    add_edge(7, 8, "back");
    add_edge(8, 2, "be-dis");

    add_edge(1, 9, "dis-be-me");
    add_edge(9, 10, "front-left");
    add_edge(10, 11, "and-left");
    add_edge(11, 12, "back");
    add_edge(12, 2, "be-dis");
};

void Graph::make_slinky_star() {
    _nodes.clear();
    add_edge(0, 1, "-");
    add_edge(1, 2, "-");

    add_edge(0, 3, "-");
    add_edge(3, 4, "-");

    add_edge(0, 5, "-");
    add_edge(5, 6, "-");

    add_edge(0, 7, "-");
    add_edge(7, 8, "-");

    add_edge(0, 9, "-");
    add_edge(9, 10, "-");

    add_edge(0, 11, "-");
    add_edge(11, 12, "-");

    add_edge(0, 13, "-");
    add_edge(13, 14, "-");
};
void Graph::make_kathy_da_grate() {
    _nodes.clear();
    add_edge(0, 1, "-");
    add_edge(1, 2, "-");
    add_edge(2, 3, "-");
    add_edge(3, 4, "-");
    add_edge(4, 0, "-");

    add_edge(0, 5, "-");
    add_edge(5, 6, "-");

    add_edge(1, 7, "-");
    add_edge(7, 8, "-");

    add_edge(2, 9, "-");
    add_edge(9, 10, "-");

    add_edge(3, 11, "-");
    add_edge(11, 12, "-");

    add_edge(4, 13, "-");
    add_edge(13, 14, "-");
};
void Graph::make_dodos_in_space() {
    _nodes.clear();
    for (size_t i = 0; i < 50; i+=2) {
        string s = "Yippee-Dodo-#";
        s += std::to_string(i);
        add_edge(i, i + 1, s);
    }
};



void Graph::make_purty_pitcher() {
    _nodes.clear();
    /*
    for (size_t j = 0; j < 10; j++) {
        add_edge(0, j, "");
    }
    for (size_t j = 11; j < 20; j++) {
        add_edge(1, j, "");
    }
    for (size_t j = 21; j < 30; j++) {
        add_edge(2, j, "");
    }
    for (size_t j = 31; j < 40; j++) {
        add_edge(3, j, "");
    }
    for (size_t j = 41; j < 50; j++) {
        add_edge(4, j, "");
    }
    for (size_t j = 51; j < 60; j++) {
        add_edge(5, j, "");
    }
    for (size_t j = 61; j < 70; j++) {
        add_edge(6, j, "");
    }
    for (size_t j = 71; j < 80; j++) {
        add_edge(7, j, "");
    }
    */
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = i*10 + 1; j < (i+1)*10; j++) {
            add_edge(i, j, "");
        }
    }

    
};

/*
for (int i = 0; i < 70; i+=7) {
        
        add_edge(i, i + 1, ".");
        add_edge(i, i + 2, ".");
        add_edge(i, i + 3, ".");
        add_edge(i, i + 4, ".");
        add_edge(i, i + 5, ".");
        add_edge(i, i + 6, ".");
        
        add_edge(i + 1, i, ".");
        add_edge(i + 1, i + 2, ".");

        add_edge(i + 3, i + 2, ".");
        add_edge(i + 3, i + 4, ".");

        add_edge(i + 5, i + 4, ".");
        add_edge(i + 5, i, ".");
        int randEdge = (i+3) % 2;
        add_edge(randEdge, i + 6, ".");
}
*/
