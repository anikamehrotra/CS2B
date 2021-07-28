// Student ID: 20480681

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Graph {
    protected:
        struct Edge {
            int _dst;
            std::string _tag;
            Edge(int dst = -1, std::string tag = "") : _dst(dst), _tag(tag) {

            }
        };
        std::vector<std::vector<Edge>> _nodes;
        // Suggested private helpers. Not tested.
        void add_edge(int src, int dst, std::string tag) {
            if (_nodes.size() < src) {_nodes.resize(src + 1);}
            _nodes[src].push_back(Edge(dst, tag));
        };
        std::string to_string() const;

    public:
        void make_silly_snake();
        void make_mr_sticky();
        void make_driftin_dragonfly();
        void make_slinky_star();
        void make_kathy_da_grate();
        void make_dodos_in_space();
        void make_purty_pitcher();
        friend class Tests; // Don't remove this line.
};

#endif /* Graph_h */