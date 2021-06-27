#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// #include "Pet.cpp"
#include "Quest 8/Stacks.h"
using namespace std;

int main() {
    Stack_Int s;
    for (int i = 0; i < 1814; i++) {
        s.push(i);
    }
    cout << s.to_string();
}