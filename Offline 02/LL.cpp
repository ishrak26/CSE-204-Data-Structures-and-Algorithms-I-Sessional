#pragma once

#include <iostream>
#include "Stack.h"

using namespace std;

template <typename E>
class LL: public Stack<E> {
    class Node {
    public:
        E val;
        Node *next;

        Node(E val, Node *next = NULL) {
            this->val = val;
            this->next = next;
        }
    };

    Node *head;
    int size;

    void init() {
        head = NULL;
        size = 0;
    }

public:
    LL() {
        init();
    }

    LL(Stack<E> *s) { // copy a given stack
        init();

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

    ~LL() {
        clear();
    }

    void clear() {
        while (head != NULL) pop();
    }

    void push(E item) {
        head = new Node(item, head);
        ++size;
    }

    E pop() {
        assert(head != NULL); // size > 0
        E ret = head->val;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        --size;
        return ret;
    }

    int length() {
        return size;
    }

    E topValue() {
        assert(head != NULL);
        return head->val;
    }

    void setDirection(int direction) {
        // do nothing
    }
};

