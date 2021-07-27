// Student ID: 20480681

#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Trie {
    private:
        struct Node {
            vector<Trie::Node *> next;

            ~Node() {
                for (size_t i = 0; i < next.size(); i++) {
                    delete next[i];
                    next[i] = nullptr;
                }
            };

            void insert(string s) {
                Trie::Node *curr = this;
                for (const char *str = s.c_str(); *str; str++) {
                    char ch = *str;
                    if ((size_t) ch >= curr->next.size()) {curr->next.resize(ch+1);}
                    if (curr->next[ch] != nullptr) {curr = curr->next[ch];}
                    else {curr = curr->next[ch] = new Trie::Node();}
                }
                // next line could be wrong so double check
                if (curr->next.size() == 0) {curr->next.resize(1);}
                if (curr->next[0] == nullptr) {curr->next[0] = new Trie::Node();}
                
            };
            const Node *traverse(string s) const {
                const Trie::Node *curr = this;
                for (const char *str = s.c_str(); *str; str++) {
                    char ch = *str;
                    // if ((size_t) ch >= curr->next.size()) {curr->next.resize(ch+1);}
                    if (curr->next[ch] != nullptr) {curr = curr->next[ch];}
                    else {return nullptr;}
                    // else {curr = curr->next[ch] = new Trie::Node();}
                }
                // next line could be wrong so double check
                // if (curr->next.size() == 0) {curr->next.resize(1);}
                return curr;
            };
            bool lookup(string s) {
                const Trie::Node *result = this->traverse(s);
                if (result == nullptr) {return false;}
                if (result->next[0] != nullptr) {return true;}
                else {return false;}
            };
            size_t get_completions(vector<string>& completions, size_t limit) const;
        } *_root;

        // Private Trie:: helper. Returns the interior node traversing s from _root.
        const Node *traverse(string &s) {return _root->traverse(s);};
    public:
        Trie() {_root = new Node();};
        ~Trie() {delete _root; _root = nullptr;};

        void insert(string s) const {_root->insert(s);};
        bool lookup(string s) const {return _root->lookup(s);};
        size_t get_completions(string s, vector<string>& completions, size_t limit) const { return _root->traverse(s)->get_completions(completions, limit);};
        size_t trie_sort(vector<string>& vec) const;

        string to_string(size_t limit) const {
            string s;
            vector<string> completions;
            get_completions("", completions, limit+1);
            s = "# Trie contents\n";
            if (limit > completions.size()) {
                for (size_t i = 0; i < completions.size(); i++) {
                    s += completions[i] + "\n";
                }
            }
            else {
                for (size_t i = 0; i < limit; i++) {
                    s += completions[i] + "\n";
                }
                s += "...\n";
            }
            return s;
        };
        ostream& operator<<(ostream os) {return os << to_string(100);};

        friend class Tests;
};


#endif /* Trie_h */