#include <iostream>
#include "Stack.h"

using namespace std;

template <typename E>
class Arr: Stack<E> {
    E *arr;
    int top;
    int capacity;
    int direction;

    void resize() { // double the capacity
        capacity <<= 1;
        E *newArr = new E[capacity];

        if (direction == 1) {
            for (int i = 0; i < top; i++) {
                newArr[i] = arr[i];
            }
        }
        else {
            for (int i = top+1; i < capacity; i++) {
                newArr[i] = arr[i];
            }
        }

        clear();
        arr = newArr;
    }

public:
    void clear() {
        delete[] arr;
    }

    void push(E item) {
        if (direction == 1) {
            if (top == capacity) resize();
            arr[top++] = item;
        }
        else {
            if (top == -1) resize();
            arr[top--] = item;
        }
    }

    E pop() {
        assert(length() != 0);
        if (direction == 1) {
            return arr[--top];
        }

        // direction = -1
        return arr[++top];
    }

    int length() {
        if (direction == 1) {
            return top;
        }
        else {
            return capacity - top - 1;
        }
    }

    E topValue() {
        assert(length() != 0);
        if (direction == 1) {
            return arr[top-1];
        }
        else {
            return arr[top+1];
        }
    }

    void setDirection(int direction) {
        this->direction = direction;
    }
};
