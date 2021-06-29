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
    Playlist::Node *n = new Playlist::Node(a);
    

}
    