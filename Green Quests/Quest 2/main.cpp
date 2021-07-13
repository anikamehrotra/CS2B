#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Hanoi.h"
#include "Hanoi.cpp"
using namespace std;

class Tests {
    public:
        int errorCount = 0;
        
        int hanoiTest(Hanoi &h, int num_discs, int src, int dst, int tmp, string expectedResult) {

            std::string r = h.get_moves(num_discs, src, dst, tmp);
            if (r != expectedResult) {
                cout << "** Test failed: " << num_discs << " " << src << " " << dst << " " << tmp << endl;
                cout << "actual\n" + r + "\nexpected\n" + expectedResult << endl;
                errorCount++;
                return false;
            }
            else {
                cout << "   Test passed: " << num_discs << " " << src << " " << dst << " " << tmp << endl;
                return true;
            }
        }
};

int main() {
    Tests t;
    Hanoi h;
/*
    t.hanoiTest(h, 0, 1, 2, 3, "");
    t.hanoiTest(h, 1, 1, 2, 3, "1->2\n");
    t.hanoiTest(h, 2, 1, 2, 3, "1->3\n1->2\n3->2\n");
    t.hanoiTest(h, 3, 1, 2, 3, "1->2\n1->3\n2->3\n1->2\n3->1\n3->2\n1->2\n");
    t.hanoiTest(h, 3, 1, 2, 3, "1->2\n1->3\n2->3\n1->2\n3->1\n3->2\n1->2\n");
    */
    t.hanoiTest(h, 2, 2, 1, 3, "2->3\n2->1\n3->1\n");
    t.hanoiTest(h, 2, 2, 1, 3, "2->3\n2->1\n3->1\n");

    
}
