// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Automaton.h"

using namespace std;

static size_t binary_to_decimal(const vector<int>& bits) {
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    size_t len = bits.size();
    for (size_t i = len - 1; i >= 0; i--) {
        if (bits[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}