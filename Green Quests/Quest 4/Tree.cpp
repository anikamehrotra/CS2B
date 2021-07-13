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
    //_root = new Node("ROOT");
    _root = new Node(*that._root);
    // else {_root = nullptr;}
    return *this;
}

std::string Tree::to_string() const {
    string s;
    
    s += "# Tree rooted at " + _root->get_data() + "\n";
    s += "# The following lines are of the form:\n";
    s += "#   node: child1 child2...\n";
    s +=  _root->to_string();
    s += "# End of Tree\n";
    

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

/*
Hooray! 1 Nelliform crystal dessicated into methopheric molecules (node ctr)

Hooray! 2 Smalltalk Sonnets stuffed into imperative Rexmus stackings (child insertions)

Hooray! 2 Nanosecs of carelessness averted through mindful engagement (sibling insertions)
(Whoa!)

Hooray! 8 Pandrumcellos played by 1-Toe Yomoya at the grand stringual concert (=)

Hooray! 1 Zephyr of Pulchritude caressed your artwork in transit (node copy)

Hooray! 2 Shades of Zurao stripe a burgundy sky (node comparisons)

Hooray! 10 Queens of compassion decide to form an unbreakable pact (node to string)

Hooray! 1 Humongiferous ingot of polycrystalline Mobium ionized into a Lectrodragnet (node dtr)

You can keep going. Or enter the next quest. Or both.

Hooray, the complex kiwi can open secret doors.

Hooray! 2 Eager children play Trim Dandango after a liquid sunset (tree ctr/dtr)

Hooray! 2 Liters of Nyscent Rocksyjen will blecch even purple velvyt smidges (tree copy)

Hooray! 2 Gumbaugh Riffsticks suffice to scale Boron's overwall (tree comp ops)

Hooray! 1 Sunyati uses techniques never before known to Strovenkind (tree to string)

Hooray! 6 Muavino Nectarines ripened in time for guests royale (config 1)
*/