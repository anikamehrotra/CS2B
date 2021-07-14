#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Complex.cpp"
#include "Complex.h"
using namespace std;

class Tests {
    int complex_test(Complex& c, Complex& c2, bool b_expectedResult, Complex& c_expectedResult) {
        bool b_result = c == c2;
        cout << "c == c2: " << b_result << endl;
        
        b_result = c != c2;
        cout << "c != c2: " << b_result << endl;

        b_result = c < c2;
        cout << "c < c2: " << b_result << endl;
    }
};

int main() {

}