#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Hanoi.cpp"
#include "Hanoi.h"
using namespace std;

class Tests {
    public:
        int errorCount = 0;
        
        int hanoiTest(Hanoi h, int num_discs, int src, int dst, int tmp, string expectedResult) {
            std::string result = h.get_moves( num_discs,  src,  dst,  tmp);
            if (result != expectedResult) {
                cout << "** Test failed: " << num_discs << " " << src << " " << dst << " " << tmp << endl;
                cout << "actual\n" + result + "\nexpected\n" + expectedResult << endl;
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
    Hanoi h;
    Tests t;
    t.hanoiTest(h, 0, 1, 2, 3, "");
    t.hanoiTest(h, 1, 1, 2, 3, "1->2");
    
}
