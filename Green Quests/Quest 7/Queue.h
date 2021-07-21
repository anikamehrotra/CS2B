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
class Queue
{
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
    size_t size() const;
    void resize(size_t size);
    const T &peek() const;
    bool dequeue();
    bool enqueue(const T &elem);
    std::string to_string(size_t limit = MAX_DISP_ELEMS) const;
    friend class Tests; // Don't remove this line
};
template <typename T>
T Queue<T>::_sentinel = T();
template <typename T>
Queue<T>::Queue(size_t size)
{
    // TODO
}
// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.

#endif /* Queue_h */