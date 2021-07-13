// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Automaton.h"

using namespace std;

/* UNFINISHED DID NOT RECEIVE ALL TROPHIES */

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
    if (rule >= pow_2(pow_2(_num_parents))) {_is_valid = false; return false;}
    // _rules = int_to_bool_vector(decimal_to_binary(rule));

    vector<int> binary_rule = decimal_to_binary(rule);
    size_t padding = pow_2(_num_parents) - binary_rule.size();
    for (size_t i = 0; i < padding; i++) {
        _rules[i] = false;
    }
    for (size_t i = padding; i < pow_2(_num_parents); i++) {
        if (binary_rule[i - padding] == 1) {_rules[i] = true;}
        if (binary_rule[i - padding] == 0) {_rules[i] = false;}
    }
    reverse(_rules.begin(), _rules.end());
    _extreme_bit = 0;
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
    if (current_gen.size() == 0) {next_gen = {1}; return true;}
    if (current_gen.size() %2 == 0) {return false;}
    next_gen.clear();
    vector<int> intermediate_gen = current_gen;
    for (size_t j = 0; j < _num_parents-1; j++) {
        intermediate_gen.insert(intermediate_gen.begin(), _extreme_bit);
        intermediate_gen.push_back(_extreme_bit);
    }
    for (size_t i = 0; i < current_gen.size() + _num_parents - 1; i++) {
        next_gen.push_back(_rules[translate_n_bits_starting_at(intermediate_gen, i, _num_parents)]);
    }
    vector<int> temp_current_extreme_bits;
    for (size_t k = 0; k < _num_parents; k++) {
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
    for (size_t i = pos; i < pos + n; i++) {
        translation.push_back(bits[i]);
    }
    // if (translation.size() != n) {cout << "Uh oh, wrong size slice" << endl;}
    return binary_to_decimal(translation);
}

std::string Automaton::generation_to_string(const vector<int>& gen, size_t width) {
    string s = "";
    if (width % 2 == 0) {return s;}
    //if (gen.size() > width) {return s;}
    if (gen.size() % 2 == 0) {return s;}
    for (size_t i = 0; i < gen.size(); i++) {
        if (gen[i] == 1) {s += "*";}
        else {s += " ";}
    }
    if (gen.size() < width) {
        for (size_t i = 0; i < (width-gen.size())/2; i++) {
            string c = " ";
            if (_extreme_bit == 1) {c = "*";}
            s.insert(0, c);
            s.insert(s.size(), c);
        }
    }
    if (gen.size() > width) {
        s.erase(s.begin(), s.begin() + (gen.size()-width)/2);
        s.erase(s.end() - (gen.size()-width)/2, s.end());
    }
    return s ;
}

string Automaton::get_first_n_generations(size_t n, size_t width) {
    if (width <= 0) {return "";}
    string s = "";
    string temp;
    vector<int> current_gen;
    vector<int> next_gen;
    for (size_t i = 0; i <= n; i++) {
        temp = generation_to_string(current_gen, width);
        if (temp != "") {
            s += temp + "\n";
        }
        make_next_gen(current_gen, next_gen);
        current_gen = next_gen;
    }
    return s;
}

/*
Hooray! 3 Transfer Credits earn a trip to Luminare's Levitating Emporium (utils)

Hooray! 4 Conditions agreed upon by the sparring trio (set rule)

Hooray! 1 Bottle of Crypiscid Distillate exchanged for a balloon axe (constructor)

Hooray! 3 Prosphuric Monocrystamate molecules energized to ionization level 1.729 (equals)

Hooray! 6 Pillars of solpitude provide the strength you need (make_next_gen)

Hooray! 3 Phlags of intergalactic victory hoisted before waking up (generation to string)

You can keep going. Or enter the next quest. Or both.

Hooray, krazy the koala knows where to go nowhere to go.

Alas! Aut(1,3).get_first_n...(n:10,wid:11) gave us different results.
You said:
***********
***********
***********
***********
***********
***********
***********
***********
***********
***********

But I expected:
     *     
***********
***********
***********
***********
***********
***********
***********
***********
***********

Auto da yours: { valid = 1, num_parents = 1, extreme = 1, rules = [ 1 1 ] }
Auto da mines: { valid = 1, num_parents = 1, extreme = 1, rules = [ 1 1 ] }
*/