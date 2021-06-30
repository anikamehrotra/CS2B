// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Hanoi.h"

using namespace std;

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {
    if (_cache[num_discs][src][dst].empty() == true) {return "";}
    return _cache[num_discs][src][dst];
}


std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
    if (num_discs == 0) {return "";}
    if (num_discs == 1) {
        return std::to_string(src) + "->" + std::to_string(dst) + "\n";
    }
    return 
        get_moves(num_discs-1, src, tmp, dst) + 
        std::to_string(src) + "->" + std::to_string(dst) + "\n" + 
        get_moves(num_discs-1, tmp, dst, src);
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    return "Below, 'A->B' means 'move the top disc on pole A to pole B'" + 
        get_moves(num_discs, src, dst, tmp);
}