#pragma once

#include <iostream>

using namespace std;

template <typename E>
class Queue {

public:
    virtual void clear() = 0;
    virtual void enqueue(const E item) = 0;
    virtual E dequeue() = 0;
    virtual int length() const = 0;
    virtual E frontValue() const = 0;
    virtual E rearValue() const = 0;
    virtual E leaveQueue() = 0;
};
