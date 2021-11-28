#include <iostream>
#include "Stack.h"

using namespace std;

template <typename E>
class LL: Stack<E> {
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

public:
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
        Node *tmp = new Node(item, head->next);
        delete head;
        head = tmp;
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

