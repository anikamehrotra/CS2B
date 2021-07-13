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
            Node(std::string s = "") { _data = s; _sibling = nullptr; _child = nullptr;};                           // TODO
            Node(const Node& that) {*this = that;};                            // TODO
            const Node &operator=(const Node &that) {
                if (this != &that) {
                    /*
                    _data = that._data;
                    _sibling = that._sibling;
                    _child = that._child;
                    */
                
                   std::string new_data = that._data;
                   set_data(new_data);
                   _sibling = new Node();
                   *_sibling = *that._sibling;
                   _child = new Node();
                   *_child = *that._child;
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
                if (_sibling == nullptr) {
                    _sibling = p; 
                    return this;
                }
                else return _sibling->insert_sibling(p);
                /*
                Node *lastSibling = _sibling;
                if (lastSibling == nullptr) {lastSibling = p; return this;}
                while (lastSibling != nullptr) {
                    if (lastSibling->_sibling == nullptr) {lastSibling->_sibling = p; return this;}
                    lastSibling = lastSibling->_sibling;
                }
                lastSibling = p;
                return this;
                */
            };
            Node *insert_child(Node *p) {
                if (_child == nullptr) {_child = p;}
                else {_child->insert_sibling(p);}
                return this;
            };
            std::string to_string() const {
                string s = "";
                s += _data + " :";
                Node *ptr = _child;
                while (ptr != nullptr) {
                    s += " " + ptr->_data;
                    ptr = ptr->_sibling;
                }
                s += "\n";
                if (_child != nullptr) {
                    s += "# Child of " + _data + "\n" + _child->to_string();
                }
                if (_sibling != nullptr) {
                    s += "# Next sib of " + _data + "\n" + _sibling->to_string();
                }
                
                return s;
            };
            bool operator==(const Node &that) const {return is_equal(this, &that);};
            bool operator!=(const Node &that) const {return !is_equal(this, &that);};
        };
        Node *_root;

    public:
        Tree();
        ~Tree();
        Tree(const Tree &that) {
            if (this == &that) {return;}
            *this = that; 
        }
        Tree &operator=(const Tree &that); // Deep clone
        std::string to_string() const;
        void make_special_config_1(const std::vector<std::string> &names);
        bool operator==(const Tree &that) const
        {
            if (_root == that._root) {return true;}
            return false;
        }
        bool operator!=(const Tree &that) const
        {
            if (_root != that._root) {return true;}
            return false;
        }
        friend std::ostream &operator<<(std::ostream &os, const Tree &tree){
            return os << tree.to_string();
        };
        friend class Tests; // Don't remove this line
};

#endif /* Automaton_h */