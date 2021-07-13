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
    string treeString = tree.to_string();

    Tree tree2;
    tree2.make_special_config_1(names);
    cout << (tree == tree2) << endl;

    Tree tree3(tree);
    // tree3 = tree;
    cout << tree3.to_string() << endl;
    cout << (tree == tree3) << endl;
    string treeString3 = tree3.to_string();

    cout << "treeString == treeString3: " << (treeString == treeString3) << endl;
}