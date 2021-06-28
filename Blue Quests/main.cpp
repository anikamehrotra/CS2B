#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// #include "Pet.cpp"
#include "Quest 9/String_List.h"
using namespace std;

int main() {
    String_List sl;
    sl.insert_at_current("e");
    sl.insert_at_current("d");
    sl.insert_at_current("c");
    sl.insert_at_current("b");
    sl.insert_at_current("a");
    sl.rewind();
    sl.advance_current();
    sl.advance_current();
    sl.insert_at_current("f");
    // sl.clear();
    // cout << sl.get_size();
    cout << sl.to_string();
    sl.clear();
    cout << sl.to_string();
}