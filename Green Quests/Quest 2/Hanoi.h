// Student ID: 20480681

#ifndef Hanoi_h
#define Hanoi_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>




using namespace std;

class Hanoi {
    private:
        int _num_poles = 4;
        int _num_discs = 10;
        // TODO: Declare the _cache member using an appropriate
        // level of nesting within std::vectors to put each string
        // of moves. You should be able to access the cache like so:
        // _cache[num_discs][src][dst] = "move1\nmove2\n..."
        vector<vector<vector<string>>> _cache;
        //_cache = vector<vector<vector<string>>>(_num_discs, vector<vector<string> >(_num_poles, vector<string>(_num_poles)));


        std::string lookup_moves(int num_discs, int src, int dst);
        std::string get_moves(int num_discs, int src, int dst, int tmp);

    public:
        // Use freebie default constructor
        Hanoi() {
            for (int i = 0; i < _num_discs; i++)
                for (int j = 0; j < _num_poles; j++)
                    for (int k = 0; k < _num_poles; k++)
                        _cache[i][j][k] = "";
        }
        std::string solve(int num_discs, int src, int dst, int tmp);
        friend class Tests; // Don't remove this line
};

#endif /* Hanoi_h */