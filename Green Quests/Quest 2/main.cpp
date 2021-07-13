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

        string cacheTest(Hanoi &h) {
            string s;
            for (int i = 0; i < h._cache.size(); i++) {
                for (int j = 0; j < h._cache[i].size(); j++) {
                    for (int k = 0; k < h._cache[i][j].size(); k++) {
                        s += "_cache[" + to_string(i) + "][" + to_string(j) + "][" + to_string(k) + "] = " + h._cache[i][j][k] + "\n";                      
                        //+ i + i + "][" + j + "][" + k + "] = "
                         //    + h._cache[i][j][k] + "\n";
                    } 
                }
            }
            return s;
        }

};

int main() {
    Tests t;
    Hanoi h;

    /*
    t.hanoiTest(h, 0, 1, 2, 3, "");
    cout << t.cacheTest(h);
    */
    t.hanoiTest(h, 1, 1, 2, 3, "1->2\n");
    cout << t.cacheTest(h);
    t.hanoiTest(h, 1, 1, 3, 2, "1->3\n");
    cout << t.cacheTest(h);
    t.hanoiTest(h, 1, 1, 2, 3, "1->2\n");
    cout << t.cacheTest(h);
    t.hanoiTest(h, 2, 3, 2, 1, "3->1\n3->2\n1->2\n");
    cout << t.cacheTest(h);
    /*
    t.hanoiTest(h, 2, 1, 2, 3, "1->3\n1->2\n3->2\n");
    t.hanoiTest(h, 3, 1, 2, 3, "1->2\n1->3\n2->3\n1->2\n3->1\n3->2\n1->2\n");
    t.hanoiTest(h, 3, 1, 2, 3, "1->2\n1->3\n2->3\n1->2\n3->1\n3->2\n1->2\n");
    
    t.hanoiTest(h, 2, 2, 1, 3, "2->3\n2->1\n3->1\n");
    t.hanoiTest(h, 2, 2, 1, 3, "2->3\n2->1\n3->1\n");
*/  

    
}
