#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>

#include "Queue.h"
#include "Queue.cpp"
using namespace std;

class Tests {
    public:
};

int main() {
    Queue<int> q(5); cout << q.to_string() << endl;
    Queue<int>::set_sentinel(0); cout << q.to_string() << endl;
    q.enqueue(1); cout << q.to_string() << endl;
    q.enqueue(2); cout << q.to_string() << endl;
    q.enqueue(3); cout << q.to_string() << endl;
    q.enqueue(4); cout << q.to_string() << endl;
    q.enqueue(5); cout << q.to_string() << endl;
    q.resize(10); cout << q.to_string() << endl;
}