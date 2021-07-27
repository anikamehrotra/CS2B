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
    completions.clear();
    unprocessed_nodes.push(Continuation(this, ""));

    while(!unprocessed_nodes.empty() && completions.size() < limit) {
        Continuation cont = unprocessed_nodes.front();
        unprocessed_nodes.pop();
        if (cont.node->next.size() == 0) {completions.push_back(cont.partial);}
        if (cont.node->next[0] != nullptr) {completions.push_back(cont.partial);}
        for (size_t i = 1; i < cont.node->next.size(); i++) {
            if (cont.node->next[i] != nullptr) {
                unprocessed_nodes.push(Continuation(cont.node->next[i], cont.partial + (char) i));
            }
        }

    }
    
    return completions.size();
}

size_t Trie::trie_sort(vector<string>& vec) const {
    vec.clear();
    get_completions("", vec, 100000);
    return vec.size();
}