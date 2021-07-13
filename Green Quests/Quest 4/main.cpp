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
    Tree treeFromStrings;
    std::vector<std::string> names = { "AABA", "ABAB", "ABBA", "BABA", "COBO", "COCO", "CODO", "COFO", "COGO", "COHO", "COJO", "COKO", "DIBI", "DIDI", "DIFI", "DIGI", "DIHI", "DIJI", "DIKI", "DILI" };
    treeFromStrings.make_special_config_1(names);
    cout << treeFromStrings.to_string() << endl;
    string sTreefromStrings = treeFromStrings.to_string();

    Tree treeFromStringsAgain;
    treeFromStringsAgain.make_special_config_1(names);
    cout << (treeFromStrings == treeFromStringsAgain) << endl;

    Tree treeFromDeepCopy(treeFromStrings);
    // tree3 = tree;
    cout << treeFromDeepCopy.to_string() << endl;
    cout << (treeFromStrings == treeFromDeepCopy) << endl;
    string sTreeFromDeepCopy = treeFromDeepCopy.to_string();

    cout << "sTreefromStrings == sTreeFromDeepCopy: " << (sTreefromStrings == sTreeFromDeepCopy) << endl;

    Tree treeFromDeepCopyEquals;
    std::vector<std::string> namesDifferent = { "aaba", "abab", "abba", "baba", "cobo", "coco", "codo", "cofo", "cogo", "coho", "cojo", "coko", "dibi", "didi", "difi", "digi", "dihi", "diji", "diki", "dili" };

    treeFromDeepCopyEquals.make_special_config_1(namesDifferent);
    cout << treeFromDeepCopyEquals.to_string() << endl;
    cout << (treeFromStrings == treeFromDeepCopyEquals) << endl;
    string sTreeFromDeepCopyEquals = treeFromDeepCopyEquals.to_string();
    treeFromDeepCopyEquals = treeFromStrings;
    cout << "sTreefromStrings == sTreeFromDeepCopyEquals: " << (sTreefromStrings == sTreeFromDeepCopyEquals) << endl;    

    // tree3 = tree;
    cout << treeFromDeepCopyEquals.to_string() << endl;
    cout << (treeFromStrings == treeFromDeepCopyEquals) << endl;
    sTreeFromDeepCopyEquals = treeFromDeepCopyEquals.to_string();

    cout << "sTreefromStrings == sTreeFromDeepCopyEquals: " << (sTreefromStrings == sTreeFromDeepCopyEquals) << endl;    
}