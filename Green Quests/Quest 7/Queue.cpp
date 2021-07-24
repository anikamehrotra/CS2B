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
    size_t i = _data.size()-1;
    while (!is_empty()) {
        temp.enqueue(_data[i];)
        _data.dequeue();
        i--;
    }
    _data = temp._data;
}

template <typename T> void popalot(Queue<T>& q) {
    while (!q.is_empty()) {
        q.dequeue();
    }
}

template <typename T> string Queue<T>::to_string(size_t lim) const {
    string s = "";
    s += "# Queue - size = ";
    s += _data.size() + "\n";
    s += "data : ";
    if (lim >= _data.size()) {
        for (size_t i = 0; i < _data.size(); i++) {
            s += _data[i] + " ";
        }
    }
    else if (lim < _data.size()) {
        for (size_t i = 0; i < lim; i++) {
            s += _data[i] + " ";
        }
        s += "...";
    }
    s += "\n";
}