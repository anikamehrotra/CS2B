#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Quest 2/Hanoi.h"
#include "Quest 2/Hanoi.cpp"
using namespace std;

class Tests {
    public:
        int errorCount = 0;
        
        int hanoiTest(int num_discs, int src, int dst, int tmp, string expectedResult) {
            Hanoi h;
            std::string r = "";
            h.get_moves(num_discs, src, dst, tmp);
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

    t.hanoiTest(0, 1, 2, 3, "");
    t.hanoiTest(1, 1, 2, 3, "1->2");
    
}
