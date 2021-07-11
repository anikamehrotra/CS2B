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
            static bool is_equal(const Node *p1, const Node *p2);
            Node(std::string s = "") { _data = s;};                           // TODO
            Node(const Node& that);                            // TODO
            const Node &operator=(const Node &that);           // Deep clone
            ~Node();
            std::string get_data() const { return _data; }
            void set_data(std::string s) { _data = s; }
            Node *insert_sibling(Node *p) {
                size_t i = 0;
                while (_sibling != nullptr) {
                    i++;
                }
            };
            Node *insert_child(Node *p);
            std::string to_string() const;
            bool operator==(const Node &that) const;
            bool operator!=(const Node &that) const;
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