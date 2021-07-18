#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>

#include "Shapes.h"
#include "Shapes.cpp"
using namespace std;

class Tests {
    public:

        void test_fill_screen(Screen *s, char c, string expectedOutput) {
            s->fill(c);
            test_to_string(s, expectedOutput);
        }

        void test_to_string(Screen *s, string expectedOutput) {
            string output = s->to_string();
            assert(output == expectedOutput);
            cout << expectedOutput << endl;
        } 

        void test_draw_point(Screen *s, int x, int y, char c, string expectedOutput) {
            Point p(x, y);
            s->fill(' ');
            p.draw(*s, c);
            test_to_string(s, expectedOutput);
        }
};

int main() {
    Tests t;
    string output;

    t.test_fill_screen(new Screen(3, 3), 'c', "ccc\nccc\nccc\n");
    t.test_fill_screen(new Screen(2, 1), 'c', "cc\n");
    t.test_fill_screen(new Screen(1, 2), 'c', "c\nc\n");
    t.test_fill_screen(new Screen(1, 1), 'c', "c\n");
    t.test_fill_screen(new Screen(0, 0), 'c', "");
//  t.test_fill_screen(new Screen(0, -1), 'c', "");
    t.test_draw_point(new Screen(3, 3), 0, 0, 'c', "  \n   \nc   \n");


/*
    s = new Screen(0, 0); s->fill('c'); output = s->to_string();
    assert(output == ""); 
    cout << output << endl;
    delete s;

    s = new Screen(3, 3); s->fill('c'); output = s->to_string();
    assert(output == "ccc\nccc\nccc\n");
    cout << output << endl;
    delete s; */
}