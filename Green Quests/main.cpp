#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Quest 1/Playlist.cpp"
#include "Quest 1/Playlist.h"
using namespace std;

class Tests {
    public:
        bool testVerboseLevel = 2; // 0: no output, 1: false cases only, 2: all output
        

    bool nodeTest() {
        Playlist::Song_Entry a(1, "a");
        Playlist::Song_Entry b(2, "b");
        Playlist::Song_Entry c(3, "c");
        Playlist::Song_Entry d(4, "d");

        Playlist::Node *n1 = new Playlist::Node(a);
        Playlist::Node *n2 = new Playlist::Node(b);
        Playlist::Node *n3 = new Playlist::Node(c);
        Playlist::Node *n4 = new Playlist::Node(d);

        n1->insert_next(n2)->insert_next(n3)->insert_next(n4);
        if (nodeStringMaker(n1) != "abcd") return testFailed("node test failed");
        n1->remove_next();
        if (nodeStringMaker(n1) != "acd")  return testFailed("node test failed");
        n1->insert_next(new Playlist::Node(b));
        if (nodeStringMaker(n1) != "abcd") return testFailed("node test failed");
        n1->remove_next();
        if (nodeStringMaker(n1) != "acd")  return testFailed("node test failed");
        n1->remove_next();
        if (nodeStringMaker(n1) != "ad")   return testFailed("node test failed");
        n1->remove_next();
        if (nodeStringMaker(n1) != "a")    return testFailed("node test failed");
        n1->remove_next();
        if (nodeStringMaker(n1) != "a")    return testFailed("node test failed");
        

        // ASSERT
        if(n1->_next != nullptr) return false;
        cout << "removeNodeTest Passes" << endl;
        return true;
    }

    bool testFailed(string s) {
        cout << s << endl;
        return false;
    }

    bool testPlaylist(Playlist &p, string expectedResult) {
        if(p.to_string_short() != expectedResult) {
            if(testVerboseLevel >= 1) {cout << "Playlist test failed: " << expectedResult << endl;}
            return false;
        }
        if(testVerboseLevel >= 2) {cout << "Playlist test succeeded: " << expectedResult << endl;}

        return true;
    }

    std::string nodeStringMaker(Playlist::Node *n) {
        std::string s = "";
        while (n != nullptr) {
              
            s += n->get_song().get_name();   
            n = n->get_next();
        }
        return s;
    }
    bool playlistTest() {
        Playlist p;

        Playlist::Song_Entry a(1, "a");
        Playlist::Song_Entry b(2, "b");
        Playlist::Song_Entry c(3, "c");
        Playlist::Song_Entry d(4, "d");

        Playlist::Node *n1 = new Playlist::Node(a);
        Playlist::Node *n2 = new Playlist::Node(b);
        Playlist::Node *n3 = new Playlist::Node(c);
        Playlist::Node *n4 = new Playlist::Node(d);



        p.push_back(a);       if(!testPlaylist(p, "1a[T]")) return false;
        p.push_back(b);       if(!testPlaylist(p, "2ab[T]")) return false;
        p.push_back(c);       if(!testPlaylist(p, "3abc[T]")) return false;
        p.push_back(d);       if(!testPlaylist(p, "4abcd[T]")) return false;
        p.remove_at_cursor(); if(!testPlaylist(p, "3bcd[T]")) return false;
        p.remove_at_cursor(); if(!testPlaylist(p, "2cd[T]")) return false;
        p.remove_at_cursor(); if(!testPlaylist(p, "1dt[T]")) return false;
        p.remove_at_cursor(); if(!testPlaylist(p, "0")) return false;
        /*
        p.push_front(Playlist::Song_Entry(1, "b"))->push_front(Playlist::Song_Entry(2, "a"));
        if (p.to_string_short() != "2ab")  return testFailed("playlist test failed");
        p.clear();
        if (p.to_string_short() != "0")  return testFailed("playlist test failed");
        */
        return true;
    }
    
};


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
    Tests t;
    cout << "Test 1: " << t.nodeTest() << endl;
    cout << "Test 2: " << t.playlistTest() << endl;

}
    

