#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Shapes.cpp"
#include "Shapes.h"
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
    Screen s(10, 10);
    s.fill('c');
    s.to_string();
}