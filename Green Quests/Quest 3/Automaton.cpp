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
    _extreme_bit = 1;
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
    if (n > 0) {
        // vector to store binary number
        vector<int> binaryNum;
    
        // counter for binary vector
        int i = 0;
        while (n > 0) {
            // storing remainder in binary vector
            int rem = n % 2;
            binaryNum.push_back(rem);
            n = n / 2;
            i++;
        }
        reverse(binaryNum.begin(), binaryNum.end());

        return binaryNum;
    }
    else {
        return {0};
    }
}

size_t Automaton::translate_n_bits_starting_at(const vector<int>& bits, size_t pos, size_t n) {
    if (n == 0) {return 0;}
    if (bits.begin() + pos + n > bits.end()) {return 0;}
    vector<int> translation;
    for (int i = pos; i < pos + n; i++) {
        translation.push_back(bits[i]);
    }
    // if (translation.size() != n) {cout << "Uh oh, wrong size slice" << endl;}
    return binary_to_decimal(translation);
}

std::string Automaton::generation_to_string(const vector<int>& gen, size_t width) {
    string s = "";
    if (width % 2 == 0) {return s;}
    if (gen.size() > width) {return s;}
    // if (gen.size() % 2 == 0) {return s;}
    for (int i = 0; i < gen.size(); i++) {
        if (gen[i] == 1) {s += "*";}
        else {s += " ";}
    }
    for (int i = 0; i < (width-gen.size())/2; i++) {
        string c = " ";
        if (_extreme_bit == 1) {c = "*";}
        s.insert(0, c);
        s.insert(s.size(), c);
    }
    return s;
}