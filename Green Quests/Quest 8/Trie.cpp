// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#include "Trie.h"
using namespace std;

size_t Trie::Node::get_completions(vector<string>& completions, size_t limit) const {
    struct Continuation {
        const Trie::Node *node;
        string partial;
        Continuation(const Node *p, string s): node(p), partial(s) {}
    };

    //All string descendants of this node are completions
    queue<Continuation> unprocessed_nodes;

    while(!unprocessed_nodes.empty()) {
        Continuation cont = unprocessed_nodes.front();
        unprocessed_nodes.pop();


    }
    
    return completions.size();
}