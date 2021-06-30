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
    return this;
}

Playlist *Playlist::push_front(const Song_Entry& s) {
    _prev_to_current = _head;
    insert_at_cursor(s);
    return this;
}

Playlist *Playlist::advance_cursor() {
    if (_prev_to_current == _tail) {return nullptr;}
    else {_prev_to_current = _prev_to_current->get_next(); return this;} 
}

Playlist *Playlist::circular_advance_cursor() {
    if (_prev_to_current == _tail) {_prev_to_current = _head->get_next(); return this;}
    else {_prev_to_current = _prev_to_current->get_next(); return this;}
}

Playlist::Song_Entry &Playlist::get_current_song() const {
    if (_prev_to_current->get_next() != nullptr) {return _prev_to_current->get_next()->get_song();}
    else {return this->_head->get_song();}
}

Playlist *Playlist::remove_at_cursor() {
    if (_prev_to_current->get_next() == nullptr) {return this;}
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
    s += " " + get_current_song().get_name();
    return s;
}

/*
Hooray! 4 Overhead Goals scored before the match even started (Song_Entry)
 (This time, remember to score during the match also)

Hooray! 2 Twuboggen Turtles twirled with your thumbtip (Node insertions)

Hooray! 3 Curmudgeonous Conquistadors swore allegiance to the Crown of Kindness (Node removal)

Hooray! 3 Quarterdyne dispatches arrived with good news (insert at cursor)

Hooray! 2 Knudsacks of Sucrebones stashed away in secret cellars (push back)

Hooray! 1 Tumbleweed Sandeater keeps following you around (push front)

Hooray! 2 Swillsonian Lullabies composed for her highness, Princess of Orovia (advance)

Hooray! 2 Spires of F'borgania raised at the last moment (circular advance)

Hooray! 2 Rantangular Boxymerons tiled into a large container (get current)

You can keep going. Or enter the next quest. Or both.

The secret password is hare today hanoi tomorrow

Hooray! 2 Secret Passageways out of Tymanoor Green Fort discovered (remove song)

Hooray! 1 Sharp Pfulcamarden Cheese Log excavated in Area 1729 (rewind)

Hooray! 1 Light of Leavenworth shines through the dark night (getsize)

Hooray! 1 day when Gudfort opens doors to kind hearted citizens (clear)

Hooray! 3 Contending Hypertheories merged into one hypothesis (find)

Hooray! 4 Portmanteau points stuffed into one mini-reward (to_string)
*/