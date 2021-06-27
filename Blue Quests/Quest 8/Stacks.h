// Student ID: 12345678
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h
#include <vector>
#include <sstream>
class Stack_Int
{
private:
    std::vector<int> _data;

public:
    // No explicit constructor or destructor
    size_t size() const
    {
        // TODO - Your code here
    }
    bool is_empty() const
    {
        // TODO - Your code here
    }
    void push(int val)
    {
        // TODO - Your code here
    }
    int top(bool &success) const
    {
        // TODO - Your code here
    }
    bool pop()
    {
        // TODO - Your code here
    }
    bool pop(int &val)
    {
        // TODO - Your code here
    }
    std::string to_string() const
    {
        // TODO - Your code here
    }
    // Don't remove the following line
    friend class Tests;
};
class Stack_String
{
    // TODO - Your code here. Ask in the forums if you're stuck.
};
#endif /* Stacks_h */
