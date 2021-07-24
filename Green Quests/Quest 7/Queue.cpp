// Student ID: 20480681

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Queue.h"
using namespace std;

template <typename T> bool Queue<T>::is_empty() const {
    if (_head == _tail) return true;
    return false;
}

template <typename T> bool Queue<T>::enqueue(const T& elem) {
    if (_head != (tail + 1) % _data.size()) {
        _data[_tail] = elem;
        _tail++;
    }
    return false;
}

template <typename T> bool Queue<T>::dequeue() {
    if (!is_empty()) {_data[head] = 0; head++;}
    return false;
}

template <typename T> void Queue<T>::resize(size_t size) {
    Queue <T> temp(size);
    
}