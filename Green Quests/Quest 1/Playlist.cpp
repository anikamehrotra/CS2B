#include <iostream>
#include <sstream>

#include "Playlist.h"

using namespace std;

Playlist::Playlist() {
    Playlist::Song_Entry *s = new Playlist::Song_Entry(-1, "HEAD");
    Playlist::Node *n = new Playlist::Node(*s);
    _head = n;
    _tail = n;
    _prev_to_current = n;
    _size = 0;
}

Playlist::~Playlist() {
    clear();
    delete _head;
    _size = 0;
}