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