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
       void test_get_completions (Trie &t, string s, vector<string> &completions, size_t limit) {
           t.get_completions(s, completions, limit);
           for (size_t i = 0; i < completions.size(); i++) {
               cout << " " << completions[i];
           }
       }
};

int main() {
    Tests test;
    Trie t;
    t.insert("hello");
    t.insert("he");
    cout << "lookup he: " << t.lookup("he") << endl;
    cout << "lookup h: " << t.lookup("h") << endl;
    cout << "lookup a: " << t.lookup("a") << endl;
    cout << "lookup hello: " << t.lookup("hello") << endl;
    cout << "lookup helloz: " << t.lookup("helloz") << endl;
    // cout << t.to_string(100) << endl;
    vector<string> completions;
    test.test_get_completions(t, "", completions, 1000);
}