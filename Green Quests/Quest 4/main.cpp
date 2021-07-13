#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Tree.cpp"
#include "Tree.h"
using namespace std;

class Tests {

};

int main() {
    Tree tree;
    std::vector<std::string> names = { "AABA", "ABAB", "ABBA", "BABA", "COBO", "COCO", "CODO", "COFO", "COGO", "COHO", "COJO", "COKO", "DIBI", "DIDI", "DIFI", "DIGI", "DIHI", "DIJI", "DIKI", "DILI" };
    tree.make_special_config_1(names);
    cout << tree.to_string() << endl;

    Tree tree2;
    tree2 = tree;
    cout << (tree == tree2) << endl;
}