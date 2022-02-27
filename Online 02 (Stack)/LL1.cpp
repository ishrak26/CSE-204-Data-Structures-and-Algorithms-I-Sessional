#pragma once

#include <iostream>
#include "Stack.h"

using namespace std;

template <typename E>
class LL1: public Stack<E> {
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
    LL1() {
        init();
    }

    LL1(Stack<E> *s) { // copy a given stack
        init();

        LL1<E> tmp;
        while (s->length()) {
            tmp.push(s->pop());
        }
        while (tmp.length()) {
            push(tmp.topValue());
            s->push(tmp.pop());
        }
        assert(s->length() == length());
    }

    ~LL1() {
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

    void insert(E item, int offset) {
		assert(offset >= 0 && offset < length());
		LL1<E> tmp;
		for (int i = 0; i <= offset; i++) {
			tmp.push(pop());
		}
		push(item);
		while (tmp.length()) {
			push(tmp.pop());
		}
    }

    E remove(int offset) {
		assert(offset >= 0 && offset < length());
		LL1<E> tmp;
		for (int i = 0; i < offset; i++) {
			tmp.push(pop());
		}
		E ret = pop();
		while (tmp.length()) {
			push(tmp.pop());
		}
		return ret;
    }
};


