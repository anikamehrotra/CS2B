// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Automaton.h"

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule) {
    if (num_parents > MAX_PARENTS) {_is_valid = false; return;}
    _num_parents = num_parents;
    for (size_t i = 0; i < pow_2(_num_parents); i++) {
        _rules.push_back(false);
    }
    if(!set_rule(rule)) {_is_valid = false; return;}
    // take out next line before submitting
    _extreme_bit = 0;
}

bool Automaton::set_rule(size_t rule) {
    if (_num_parents > MAX_PARENTS) {_is_valid = false; return false;}
    if (rule > pow_2(pow_2(_num_parents))) {_is_valid = false; return false;}
    // _rules = int_to_bool_vector(decimal_to_binary(rule));

    vector<int> binary_rule = decimal_to_binary(rule);
    for (size_t i = 0; i < pow_2(_num_parents) - binary_rule.size(); i++) {
        _rules[i] = false;
    }
    for (size_t i = pow_2(_num_parents) - binary_rule.size(); i < pow_2(_num_parents); i++) {
        if (binary_rule[i] == 1) {_rules[i] = true;}
        if (binary_rule[i] == 0) {_rules[i] = false;}
    }
    _is_valid = true;
    return true;
}

bool Automaton::equals(const Automaton& that) {
    if (this->_is_valid == false && that._is_valid == false) {return true;}
    if (this->_is_valid == true && that._is_valid == true && this->_num_parents == that._num_parents 
        && this->_rules == that._rules && this->_extreme_bit == that._extreme_bit) {return true;}
    return false;
}

bool Automaton::make_next_gen(const vector<int> &current_gen, vector<int> &next_gen) {  
    if (_is_valid == false) {return false;}
    if (current_gen.size() %2 == 0) {return false;}
    if (current_gen.size() == 0) {next_gen = {1}; return true;}
    next_gen.clear();
    vector<int> intermediate_gen = current_gen;
    for (int j = 0; j < _num_parents-1; j++) {
        intermediate_gen.insert(intermediate_gen.begin(), _extreme_bit);
        intermediate_gen.push_back(_extreme_bit);
    }
    for (int i = 0; i < current_gen.size() + _num_parents - 1; i++) {
        next_gen.push_back(_rules[translate_n_bits_starting_at(intermediate_gen, i, _num_parents)]);
    }
    vector<int> temp_current_extreme_bits;
    for (int k = 0; k < _num_parents; k++) {
        temp_current_extreme_bits.push_back(_extreme_bit);
    }
    _extreme_bit = _rules[binary_to_decimal(temp_current_extreme_bits)];
    return true;
}
/*
vector<bool> Automaton::int_to_bool_vector(const vector<int>& ints) {
    vector<bool> result;
    for (size_t i = 0; i < ints.size(); i++) {
        if (ints[i] == 1) {result.push_back(true);}
        if (ints[i] == 0) {result.push_back(false);}
    }
    return result;
}
*/
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
    if (gen.size() % 2 == 0) {return s;}
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