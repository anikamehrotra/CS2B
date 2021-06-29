#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Quest 1/Playlist.cpp"
#include "Quest 1/Playlist.h"
using namespace std;

int main() {
    /*
    Playlist p;
    Playlist::Song_Entry a(1, "a");
    p.push_back(a);
    Playlist::Song_Entry b(2, "b");
    p.push_back(b);
    Playlist::Song_Entry c(3, "c");
    p.push_back(c);
    Playlist::Song_Entry d(4, "d");
    p.push_back(d);

    cout << p.to_string();
    p.remove_at_cursor();
    p.remove_at_cursor();
    p.remove_at_cursor();
    p.remove_at_cursor();
    p.remove_at_cursor();
    */
    // delete &p;


    Playlist::Song_Entry a(1, "a");
    Playlist::Song_Entry b(2, "b");
    Playlist::Song_Entry c(3, "c");
    Playlist::Song_Entry d(4, "d");

    Playlist::Node *n1 = new Playlist::Node(a);
    Playlist::Node *n2 = new Playlist::Node(b);
    Playlist::Node *n3 = new Playlist::Node(c);
    Playlist::Node *n4 = new Playlist::Node(d);

    n1->insert_next(n2)->insert_next(n3)->insert_next(n4);
    n1->remove_next();
}
    