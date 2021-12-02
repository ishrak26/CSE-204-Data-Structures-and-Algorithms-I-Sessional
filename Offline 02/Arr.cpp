#pragma once

#include <iostream>
#include "Stack.h"

#define DEFAULT_SIZE 1

using namespace std;

template <typename E>
class Arr: public Stack<E> {
    E *arr;
    int top;
    int capacity;
    int direction;

    void init(int cap = DEFAULT_SIZE) {
        arr = new E[cap];
        top = 0;
        capacity = cap;
        direction = 1;
    }

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
    Arr(int x = DEFAULT_SIZE) {
        init(x);
    }

    Arr(Stack<E> *s, int x = DEFAULT_SIZE) {
        init(x);

        int len = s.length();
        E *arr = new E[len];
        for (int i = 0; i < len; i++) {
            arr[i] = s.pop();
        }
        for (int i = len-1; i >= 0; i--) {
            push(arr[i]);
            s.push(arr[i]);
        }
        assert(s.length() == len);
        delete arr;
    }

    Arr(E *arr, int direction) {
        clear();
        this->arr = arr;
        this->direction = direction;

        if (direction == 1) {
            top = 0;
        }
        else {
            capacity = sizeof(arr) / sizeof(E);
            top = capacity - 1;
        }
    }

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
