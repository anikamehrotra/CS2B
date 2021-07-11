// Student ID: 20480681

#ifndef Automaton_h
#define Automaton_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class Tree
{
    private:
        struct Node
        { // Inner class
            std::string _data;
            Node *_sibling, *_child;
            static bool is_equal(const Node *p1, const Node *p2) {
                if (p1->_sibling == p2->_sibling && p1->_child == p2->_child && p1->_data == p2->_data) {
                    return true;
                }
                return false;
            };
            Node(std::string s = "") { _data = s;};                           // TODO
            Node(const Node& that) {*this = that;};                            // TODO
            const Node &operator=(const Node &that) {
                if (this != &that) {
                    _data = that._data;
                    _sibling = that._sibling;
                    _child = that._child;
                }
                return *this;
            };           // Deep clone
            ~Node() {
                while (_child != nullptr) {
                    delete _child;
                    _child = nullptr;
                }
                while (_sibling != nullptr) {
                    delete _sibling;
                    _sibling = nullptr;
                }
            };
            std::string get_data() const { return _data; }
            void set_data(std::string s) { _data = s; }
            Node *insert_sibling(Node *p) {
                Node *ptr = _sibling;
                while (ptr->_sibling != nullptr) {
                    ptr = ptr->_sibling;
                }
                ptr->_sibling = p;
            };
            Node *insert_child(Node *p) {
                if (_child == nullptr) {_child = p;}
                else {_child->insert_sibling(p);}
            };
            std::string to_string() const {
                string s = "";
                s += _data + " :";
                Node *ptr = _sibling;
                while (ptr->_sibling != nullptr) {
                    s += " " + ptr->_data;
                }
            };
            bool operator==(const Node &that) const {return is_equal(this, &that);};
            bool operator!=(const Node &that) const {return !is_equal(this, &that);};
        };
        Node *_root;

    public:
        Tree();
        ~Tree();
        Tree(const Tree &that) { *this = that; }
        Tree &operator=(const Tree &that); // Deep clone
        std::string to_string() const;
        void make_special_config_1(const std::vector<std::string> &names);
        bool operator==(const Tree &that) const
        {
            // TODO
        }
        bool operator!=(const Tree &that) const
        {
            // TODO
        }
        friend std::ostream &operator<<(std::ostream &os, const Tree &tree){
            // TODO
        };
        friend class Tests; // Don't remove this line
};

#endif /* Automaton_h */