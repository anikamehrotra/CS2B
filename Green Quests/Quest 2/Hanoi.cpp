// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Hanoi.h"

using namespace std;

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) {
    return "";
}


std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
    if (num_discs == 0) {return "";}
    if (num_discs == 1) {
        return std::to_string(src) + "->" + std::to_string(dst) + "\n";
    }
    return 
        get_moves(num_discs-1, src, tmp, dst) + 
        std::to_string(src) + "->" + std::to_string(dst) + "\n" + 
        get_moves(num_discs-1, dst, src, tmp);
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    return "Below, 'A->B' means 'move the top disc on pole A to pole B'" + 
        get_moves(num_discs, src, dst, tmp);
}