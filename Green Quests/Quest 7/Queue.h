// Student ID: 20480681

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <typename T> 
class Queue {
private:
    std::vector<T> _data;
    size_t _head, _tail;
    static T _sentinel;

public:
    static const int MAX_DISP_ELEMS = 100;

    Queue(size_t size);

    static void set_sentinel(const T &elem) { _sentinel = elem; }
    static T get_sentinel() { return _sentinel; }

    bool is_empty() const;
    size_t size() const {
        if (_tail < _head) {
            return _tail - _head + _data.size();
        }
        return _tail - _head;
        //return _data.size();
        }
    void resize(size_t size);

    const T &peek() const {
        if (is_empty()) {return _sentinel;} 
        return _data[_head];
    }
    bool dequeue();
    bool enqueue(const T &elem);

    std::string to_string(size_t limit = MAX_DISP_ELEMS) const;

    friend class Tests; // Don't remove this line
};

template <typename T> T Queue<T>::_sentinel = T();
template <typename T> Queue<T>::Queue(size_t size) {
    _data.resize(size+1);
    _head = 0;
    _tail = 0;
}
template <typename T> void popalot(Queue<T>& q) {
    while (!q.is_empty()) {
        q.dequeue();
    }
}
// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.


template <typename T> bool Queue<T>::is_empty() const {
    if (_head == _tail) return true;
    return false;
}

template <typename T> bool Queue<T>::enqueue(const T& elem) {
    // if (size() == 0) {return false;}
    if (size() == 0 || _head != (_tail + 1) % _data.size()) {
        _data[_tail] = elem;
        _tail = _tail + 1 % _data.size();
        return true;
    }
    return false;
}

template <typename T> bool Queue<T>::dequeue() {
    if (!is_empty()) {_data[_head] = 0; _head++; return true;}
    return false;
}

template <typename T> void Queue<T>::resize(size_t size) {
    Queue <T> temp(size);
    size_t i = _head;
    while (!is_empty()) {
        temp.enqueue(_data[i % _data.size()]);
        dequeue();
        i++;
    }
    _data = temp._data;

}

template <typename T> string Queue<T>::to_string(size_t lim) const {
    string s = "";
    s += "# Queue - size = ";
    s += std::to_string(size()) + "\n";
    s += "data : ";
    if (lim >= size()) {
        for (size_t i = _head; i < size(); i++) {
            s += std::to_string(_data[i % _data.size()]) + " ";
        }
    }
    else if (lim < size()) {
        for (size_t i = _head; i < lim; i++) {
            s += std::to_string(_data[i % _data.size()]) + " ";
        }
        s += "...";
    }
    s += "\n";
    return s;
}



#endif /* Queue_h */