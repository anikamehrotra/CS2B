// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Hanoi.h"

using namespace std;

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {
    if(_cache.size() <= num_discs) _cache.resize(num_discs+1);
    if(_cache[num_discs].size() <= src) _cache[num_discs].resize(src+1);
    if(_cache[num_discs][src].size() <= dst) _cache[num_discs][src].resize(dst+1);
    if (_cache[num_discs][src][dst] == "") {return "";}
    return _cache[num_discs][src][dst];
}

/*
void Hanoi::store_moves(int num_discs, int src, int dst, string s) {

    _cache[num_discs][src][dst] = s;
}
*/

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
    if (num_discs == 0) {return "";}
    if (num_discs == 1) {
        return std::to_string(src) + "->" + std::to_string(dst) + "\n";
    }

    std::string s = lookup_moves(num_discs, src, dst);
    if (s != "") {return s;}
    s = get_moves(num_discs-1, src, tmp, dst) + 
        std::to_string(src) + "->" + std::to_string(dst) + "\n" + 
        get_moves(num_discs-1, tmp, dst, src);
    //store_moves(num_discs, src, dst, s);
    _cache[num_discs][src][dst] = s;
    return s;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    return "Below, 'A->B' means 'move the top disc on pole A to pole B'" + 
        get_moves(num_discs, src, dst, tmp);
}