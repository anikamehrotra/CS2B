#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Quest 1/Playlist.cpp"
#include "Quest 1/Playlist.h"
using namespace std;

class Tests {
    public:
        int testVerboseLevel = 2; // 0: no output, 1: false cases only, 2: all output
        int errorCount = 0;

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
            if(testVerboseLevel >= 1) {cout << "Playlist test failed: " << p.to_string_short()  << " != " << expectedResult << endl;}
            errorCount++;
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
    int playlistTest() {
        errorCount = 0;
        Playlist p;

        Playlist::Song_Entry a(1, "a");
        Playlist::Song_Entry b(2, "b");
        Playlist::Song_Entry c(3, "c");
        Playlist::Song_Entry d(4, "d");

        Playlist::Node *n1 = new Playlist::Node(a);
        Playlist::Node *n2 = new Playlist::Node(b);
        Playlist::Node *n3 = new Playlist::Node(c);
        Playlist::Node *n4 = new Playlist::Node(d);


        p.push_back(a);       testPlaylist(p, "1a[T]");
        p.push_back(b);       testPlaylist(p, "2ab[T]");
        p.push_back(c);       testPlaylist(p, "3abc[T]");
        p.push_back(d);       testPlaylist(p, "4abcd[T]");
        p.remove_at_cursor(); testPlaylist(p, "3bcd[T]");
        p.remove_at_cursor(); testPlaylist(p, "2cd[T]");
        p.remove_at_cursor(); testPlaylist(p, "1d[T]");
        p.remove_at_cursor(); testPlaylist(p, "0");

        p.push_front(Playlist::Song_Entry(1, "d"))
          ->push_front(Playlist::Song_Entry(2, "c"))
          ->push_front(Playlist::Song_Entry(3, "b"))
          ->push_front(Playlist::Song_Entry(4, "a"));
        testPlaylist(p, "4abcd[T]");
        
        p.clear();            testPlaylist(p, "0");

        p.insert_at_cursor(Playlist::Song_Entry(1, "d"))
          ->insert_at_cursor(Playlist::Song_Entry(2, "c"))
          ->insert_at_cursor(Playlist::Song_Entry(3, "b"))
          ->insert_at_cursor(Playlist::Song_Entry(4, "a"));
        testPlaylist(p, "4abcd[T]");

        p.advance_cursor();            testPlaylist(p, "4a[P]bcd[T]");
        p.rewind();                    testPlaylist(p, "4abcd[T]");

        p.advance_cursor();            testPlaylist(p, "4a[P]bcd[T]");
        p.advance_cursor();            testPlaylist(p, "4ab[P]cd[T]");
        p.advance_cursor();            testPlaylist(p, "4abc[P]d[T]");
        p.advance_cursor();            testPlaylist(p, "4abcd[P][T]");
        p.advance_cursor();            testPlaylist(p, "4abcd[P][T]");
        p.circular_advance_cursor();   testPlaylist(p, "4abcd[T]");
        p.circular_advance_cursor();   testPlaylist(p, "4a[P]bcd[T]");
        p.circular_advance_cursor();   testPlaylist(p, "4ab[P]cd[T]");
        p.circular_advance_cursor();   testPlaylist(p, "4abc[P]d[T]");
        p.circular_advance_cursor();   testPlaylist(p, "4abcd[P][T]");
        p.circular_advance_cursor();   testPlaylist(p, "4abcd[T]");
        p.circular_advance_cursor();   testPlaylist(p, "4a[P]bcd[T]");
        
        return errorCount;
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
    cout << "Test 2: " << t.playlistTest() << "failures" << endl;

}
    

