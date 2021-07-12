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
    //Tree tree;
    _root->set_data("ROOT");
    std::vector<Node*> nodes = {};
    for (size_t i = 0; i < names.size(); i++) {
        nodes.push_back(new Node(names[i]));
    }
    _root->insert_sibling(nodes[0]);
    nodes[0]->insert_child(nodes[4]);
    nodes[4]->insert_child(nodes[12]);
    nodes[4]->insert_sibling(nodes[5]);
    nodes[5]->insert_child(nodes[13]);

    nodes[0]->insert_sibling(nodes[1]);
    nodes[1]->insert_child(nodes[6]);
    nodes[6]->insert_child(nodes[14]);
    nodes[6]->insert_sibling(nodes[7]);
    nodes[7]->insert_child(nodes[15]);

    nodes[0]->insert_sibling(nodes[2]);
    nodes[2]->insert_child(nodes[8]);
    nodes[8]->insert_child(nodes[16]);
    nodes[8]->insert_sibling(nodes[9]);
    nodes[9]->insert_child(nodes[17]);

    nodes[0]->insert_sibling(nodes[3]);
    nodes[3]->insert_child(nodes[10]);
    nodes[10]->insert_child(nodes[18]);
    nodes[10]->insert_sibling(nodes[11]);
    nodes[11]->insert_child(nodes[19]);
/*
    for (size_t i = 0; i < nodes.size(); i++) {
        delete nodes[i];
        nodes[i] = nullptr;    
    } */
}