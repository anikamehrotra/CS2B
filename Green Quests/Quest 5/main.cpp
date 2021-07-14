#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Complex.cpp"
#include "Complex.h"
using namespace std;

class Tests {
    public:
    int complex_test(Complex& c, Complex& c2, bool b_expectedResult, Complex& c_expectedResult) {
        bool b_result = c == c2;
        cout << "c == c2: " << b_result << endl;
        
        b_result = c != c2;
        cout << "c != c2: " << b_result << endl;

        b_result = c < c2;
        cout << "c < c2: " << b_result << endl;

        cout << "c.get_real(): " << c.get_real() << endl;
        cout << "c.get_imag(): " << c.get_imag() << endl;

        c.set_real(c.get_real() + 1);
        c.set_imag(c.get_imag() + 1);
        cout << "c.get_real(): " << c.get_real() << endl;
        cout << "c.get_imag(): " << c.get_imag() << endl;

        cout << c.to_string() << endl;

        cout << "c.norm(): " << c.norm() << endl;
        cout << "c.norm_squared(): " << c.norm_squared() << endl;

        cout << "c.reciprocal(): " << c.reciprocal().to_string() << endl;

        cout << "c + c2: " << (c+c2).to_string() << endl;
        cout << "c - c2: " << (c-c2).to_string() << endl;
        cout << "c * c2: " << (c*c2).to_string() << endl;
        cout << "c / c2: " << (c/c2).to_string() << endl;

        c = c2;
        cout << "c = c2: c = " << c.to_string() << ", c2 = " <<  c2.to_string() << endl;

    }
};

int main() {
    Complex c(1,1);
    Complex c2(3,2);

    Tests t;
    t.complex_test(c, c2, true, Complex(2,2));
}