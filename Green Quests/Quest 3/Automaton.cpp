// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Automaton.h"

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule) {
    _num_parents = num_parents;
    // _rule = rule; 
}

size_t Automaton::binary_to_decimal(const vector<int>& bits) {
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = bits.size();
    for (int i = len - 1; i >= 0; i--) {
        if (bits[i] == 1)
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

vector<int> Automaton::decimal_to_binary(int n) {
    // vector to store binary number
    vector<int> binaryNum[32];
 
    // counter for binary vector
    int i = 0;
    while (n > 0) {
        // storing remainder in binary vector
        int rem = n % 2;
        binaryNum[i].push_back(rem);
        n = n / 2;
        i++;
    }

    return binaryNum[32];
}