#pragma once

#include <iostream>
#include "Stack.h"
#include "assert.h"

#define DEFAULT_SIZE 1

using namespace std;

template <typename E>
class Arr1: public Stack<E> {
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

        delete[] arr;
        arr = newArr;
    }

public:
    Arr1(int x = DEFAULT_SIZE) {
        assert(x > 0);
        init(x);
    }

    Arr1(Stack<E> *s) { // copy a given stack
        assert(s->length() > 0);
        init(s->length());

        Arr1<E> tmp;
        while (s->length()) {
            tmp.push(s->pop());
        }
        while (tmp.length()) {
            push(tmp.topValue());
            s->push(tmp.pop());
        }
        assert(s->length() == length());
    }

    Arr1(E *arr, int direction, int capacity = DEFAULT_SIZE) { // one array two stack
        this->arr = arr;

        assert(capacity > 0);
        this->capacity = capacity;

        assert(direction == 1 || direction == -1);
        setDirection(direction);
    }

    ~Arr1() {
        delete[] arr;
    }

    void clear() {
        delete[] arr;
        init();
    }

    void push(E item) {
        if (direction == 1) {
            if (top == capacity) resize();
            assert(top < capacity);
            arr[top++] = item;
        }
        else {
            if (top == -1) resize();
            assert(top >= 0);
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
        assert(direction == 1 || direction == -1);
        this->direction = direction;
        if (direction == -1) {
            top = capacity - 1;
        }
        else {
            top = 0;
        }
    }

    void insert(E item, int offset) {
		assert(offset >= 0 && offset < length());
		Arr1<E> tmp;
		for (int i = 0; i <= offset; i++) { // for offset k, (k+1) elements are popped first
			tmp.push(pop());
		}
		push(item);
		while (tmp.length()) {
			push(tmp.pop());
		}
    }

    E remove(int offset) {
		assert(offset >= 0 && offset < length());
		Arr1<E> tmp;
		for (int i = 0; i < offset; i++) { // for offset k, k elements are popped first
			tmp.push(pop());
		}
		E ret = pop();
		while (tmp.length()) {
			push(tmp.pop());
		}
		return ret;
    }
};

