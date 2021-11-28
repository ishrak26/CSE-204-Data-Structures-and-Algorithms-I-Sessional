#include <iostream>

using namespace std;

template <typename E>
class Stack {

public:
    virtual void clear() = 0;
    virtual void push(E item) = 0;
    virtual E pop() = 0;
    virtual int length() = 0;
    virtual E topValue() = 0;
    virtual void setDirection(int direction) = 0;
};
