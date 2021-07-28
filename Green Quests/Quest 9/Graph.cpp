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
};

void Graph::make_slinky_star() {
    _nodes.clear();
};
void Graph::make_kathy_da_grate() {
    _nodes.clear();
};
void Graph::make_dodos_in_space() {
    _nodes.clear();
};
void Graph::make_purty_pitcher() {
    _nodes.clear();
};
/*
# Graph - 6 nodes.
# Edge lists:
0 : (1,i-see) 
1 : (2,the-silly-snake) 
2 : (3,i-be) 
3 : (4,you-saw-me) 
4 : (5,once-like) 
5 : (0,kekule) 
# End of Graph

# Graph - 6 nodes.
# Edge lists:
0 : (1,i-see) 
1 : (2,the-silly-snake) 
2 : (3,I-be) 
3 : (4,you-saw-me) 
4 : (5,once-like) 
5 : (0,kekule) 
# End of Graph
*/
/*
# Graph - 7 nodes.
# Edge lists:
0 : (1,.) 
1 : (2,.) (3,.) (4,.) 
4 : (5,.) (6,.) 
# End of Graph
# Graph - 5 nodes.
# Edge lists:
0 : (1,.) 
1 : (2,.) (3,.) (4,.) 
4 : (5,.) (6,.) 
# End of Graph
*/