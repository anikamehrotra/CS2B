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

Tree::Tree(const Tree &that) {
    
}