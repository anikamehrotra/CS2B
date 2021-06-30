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
    std::string s = lookup_moves(num_discs, src, dst);
    if (s != "") {return s;}
    if (num_discs == 0) {s = "";}
    else if (num_discs == 1) {
        s = std::to_string(src) + "->" + std::to_string(dst) + "\n";
    }
    else {
        s = get_moves(num_discs-1, src, tmp, dst) + 
            std::to_string(src) + "->" + std::to_string(dst) + "\n" + 
            get_moves(num_discs-1, tmp, dst, src);
        //store_moves(num_discs, src, dst, s);
    }
    _cache[num_discs][src][dst] = s;
    return s;
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    return "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n" + 
        get_moves(num_discs, src, dst, tmp);
}

/*
Hooray! 3 Catacombs of Crossfire successfully crossed at midday (get_moves base cases).

Hooray! 5 Grand Prizes awarded at Graspro Grinstock Grand Prix (get_moves: 2-5).

Hooray! 5 Dubbadoo Dubbada Dubbadubba Doodas wish for your wellbeing (get_moves: 6-10).

Hooray! 2 Dances of Din-dinad'ash performed in mid-air (solve).

You can keep going. Or enter the next quest. Or both.

Hooray, Hooray. Merry Mynahs show the way.

Alas! Your cache was different from mine after running 2 discs.

*/