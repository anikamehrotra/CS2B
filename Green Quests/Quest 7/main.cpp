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
    Queue<int> q(5);
    Queue<int>::set_sentinel(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.resize(10);
}