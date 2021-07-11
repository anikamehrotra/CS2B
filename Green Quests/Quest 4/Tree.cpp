// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Tree.h"


using namespace std;

Tree::Tree() {
    _root = new Node("ROOT");
}

Tree::~Tree() {
    delete _root;
    _root = nullptr;
}

Tree& Tree::operator=(const Tree &that) {
    if (this == &that) {return *this;}
    _root = that._root;
    return *this;
}

std::string Tree::to_string() const {
    string s;
    s += "# Tree rooted at " + _root->get_data() + "\n";
    s += "# The following lines are of the form:\n";
    s += "#   node: child1 child2...\n";
    s +=  _root->to_string();
    s += "# End of Tree";
    return s;
}

void Tree::make_special_config_1(const std::vector<std::string> &names) {
    // names = { "AABA", "ABAB", "ABBA", "BABA", "COBO", "COCO", "CODO", "COFO", "COGO", "COHO", "COJO", "COKO", "DIBI", "DIDI", "DIFI", "DIGI", "DIHI", "DIJI", "DIKI", "DILI" };
    Tree tree;
    std::vector<Node*> nodes = {};
    for (size_t i = 0; i < names.size(); i++) {
        nodes[i] = new Node(names[i]);
    }
    _root->insert_sibling(nodes[0]);
    nodes[0]->insert_child(nodes[5]);
    nodes[5]->insert_child(nodes[13]);
}