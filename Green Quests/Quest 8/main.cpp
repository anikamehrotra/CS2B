#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>

#include "Trie.h"
#include "Trie.cpp"
using namespace std;

class Tests {
    public:
};

int main() {
    Trie t;
    t.insert("hello");
    t.insert("he");
    cout << "lookup he: " << t.lookup("he") << endl;
    cout << "lookup h: " << t.lookup("h") << endl;
    cout << "lookup a: " << t.lookup("a") << endl;
    cout << "lookup hello: " << t.lookup("hello") << endl;
    cout << "lookup helloa: " << t.lookup("helloa") << endl;
}