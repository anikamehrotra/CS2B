// Student ID: 20480681

#ifndef Automaton_h
#define Automaton_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class Automaton {
    private:
        static const size_t MAX_PARENTS = 5;
        bool _is_valid;
        size_t _num_parents; // 2^{_num_parents} = possible parent combos
};

#endif /* Automaton_h */