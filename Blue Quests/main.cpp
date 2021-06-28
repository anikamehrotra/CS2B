#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// #include "Pet.cpp"
#include "Quest 9/String_List.h"
using namespace std;

int main() {
    String_List n;
    n.insert_at_current("a");
    n.insert_at_current("b");
    n.insert_at_current("c");
    n.insert_at_current("d");
    n.insert_at_current("e");
    n.rewind();
    n.advance_current();
    n.advance_current();
    n.insert_at_current("f");
    cout << n.get_size();

}