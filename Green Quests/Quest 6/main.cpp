#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Shapes.h"
#include "Shapes.cpp"
using namespace std;

class Tests {
    public:
        void test_to_string(Screen& s, char c) {
            s.fill(c);

            s.to_string();
        } 
};

int main() {
    Tests t;
    Screen s(4, 4);
    s.fill('c');
    cout << s.to_string();
}