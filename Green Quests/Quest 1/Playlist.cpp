// Student ID: 20480681

#include <iostream>
#include <sstream>

#include "Playlist.h"

using namespace std;

Playlist::Playlist()
{
    Playlist::Song_Entry s(-1, "HEAD");
    Playlist::Node *n = new Playlist::Node(s);
    _head = n;
    _tail = n;
    _prev_to_current = n;
    _size = 0;
}

Playlist::~Playlist()
{
    clear();
    if (_head != nullptr) {delete _head;}
    _size = 0;
}

Playlist *Playlist::insert_at_cursor(const Song_Entry &s) {
    Node *n = new Node(s);
    //n->_next = _prev_to_current->_next;
    // n->insert_next(_prev_to_current->get_next());
    if (_prev_to_current->get_next() == nullptr) {_tail = n;}
    _prev_to_current->insert_next(n);

    _size++;
    return this;
}

Playlist *Playlist::push_back(const Song_Entry& s) {
    Node *n = _prev_to_current;
    _prev_to_current = _tail;
    insert_at_cursor(s);
    _prev_to_current = n;
    _size++;
    return this;
}

Playlist *Playlist::push_front(const Song_Entry& s) {
    _prev_to_current = _head;
    insert_at_cursor(s);
    _size++;
    return this;
}

Playlist *Playlist::advance_cursor() {
    if (_prev_to_current == _tail) {return nullptr;}
    else {_prev_to_current = _prev_to_current->get_next(); return this;} 
}

Playlist *Playlist::circular_advance_cursor() {
    if (_prev_to_current == _tail) {_prev_to_current = _head; return this;}
    else {_prev_to_current = _prev_to_current->get_next(); return this;}
}

Playlist::Song_Entry &Playlist::get_current_song() const {
    if (_prev_to_current != nullptr) {return _prev_to_current->get_next()->get_song();}
    else {return this->_head->get_song();}
}

Playlist *Playlist::remove_at_cursor() {
    // if (_prev_to_current->get_next() == nullptr) {return this;}
    // Node *current = _prev_to_current->get_next();
    if (_prev_to_current->get_next() == _tail) {_tail = _prev_to_current;}
    _prev_to_current->remove_next();
    // _prev_to_current->insert_next(current->get_next());
    /*if (current != nullptr) {
        delete current;
    }*/
    _size--;
    return this;
}

Playlist *Playlist::rewind() {
    _prev_to_current = _head;
    return this;
}

Playlist *Playlist::clear() {
    rewind();
    while (_head != _tail) {
        remove_at_cursor();
    }
    _size = 0;
    return this;
}

Playlist::Song_Entry &Playlist::find_by_id(int id) const {
    Node *n = _head->get_next();
    while (n != nullptr) {
        if (n->get_song().get_id() == id) {return n->get_song();}
        n = n->get_next();
    }
    return this->_head->get_song();
}

Playlist::Song_Entry &Playlist::find_by_name(string songName) const {
    Node *n = _head->get_next();
    while (n != nullptr) {
        if (n->get_song().get_name() == songName) {return n->get_song();}
        n = n->get_next();
    }
    return this->_head->get_song();
}

std::string Playlist::to_string() const {
    Node *n = _head;
    std::string s = "";
    std::string size = std::to_string(get_size());
    s += "Playlist: " + size + " entries.\n";
    int count = 0;
    while (count < 25) {
        if (n->get_next() != nullptr) {
            std::string id = std::to_string(n->get_next()->get_song().get_id());
            s += "{ id: " + id + ", name: " + n->get_next()->get_song().get_name() + " }";
            if (n->get_next() == _prev_to_current) {s += " [P]";}
            if (n->get_next() == _tail) {
                s += " [T]";
            }
            s += "\n";
            n = n->get_next();
            count++;
        }
        else {
            return s;
        }
    }
    s += "...\n";
    return s;
}

std::string Playlist::to_string_short() const {
    Node *n = _head;
    std::string s = "";
    std::string size = std::to_string(get_size());
    s += size;
    int count = 0;
    while (n->get_next() != nullptr) {
        std::string id = std::to_string(n->get_next()->get_song().get_id());
        s += n->get_next()->get_song().get_name();
        if (n->get_next() == _prev_to_current) {s += "[P]";}
        if (n->get_next() == _tail) {s += "[T]";}
        n = n->get_next();
        count++;
    }
    return s;
}