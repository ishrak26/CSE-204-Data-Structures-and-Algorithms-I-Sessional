#include <iostream>
#include <assert.h>
#include "List.h"

using namespace std;

template <typename E>
class LL : public List<E> {
    class Node {
    public:
        E val;
        Node *next;
        Node *prev;

        Node(const E &val, Node *next = NULL, Node *prev = NULL) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

    Node *head;
    Node *tail;
    Node *curr;
    int size;
    int pos;

    void init() {
        head = tail = curr = NULL;
        size = 0;
        pos = 0;
    }

    void removeCurr() {
        assert(curr != NULL);
        if (curr->prev != NULL) curr->prev->next = curr->next;
        if (curr->next != NULL) curr->next->prev = curr->prev;
        if (tail == curr) tail = curr->prev;
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
        --size;
    }

public:
    LL() {
        init();
    }

    LL(List<E> *L) {
        init();

        int tmp = L->currPos();
        for (L->moveToStart(); L->currPos() < L->length(); L->next()) {
            append(L->getValue());
        }
        L->moveToPos(tmp);
    }

    ~LL() {
        clear();
    }

    void clear() {
        moveToStart();
        while (head != NULL) removeCurr();
    }

    void insert(const E &item) {
        if (size == 0) {
            head = tail = curr = new Node(item);
        }
        else {
            curr->next = new Node(item, curr->next, curr);
            if (tail == curr) tail = tail->next;
        }
        ++size;
    }

    void append(const E &item) {
        if (size == 0) {
            head = tail = curr = new Node(item);
        }
        else {
            tail->next = new Node(item, tail->next, tail);
            tail = tail->next;
        }
        ++size;
    }

    // Remove and return the current element
    E remove() {
        assert(curr != NULL);
        E item = curr->val;
        removeCurr();
        return item;
    }

    void moveToStart() {
        curr = head;
        pos = 0;
    }

    void moveToEnd() {
        assert(size > 0);
        curr = tail;
        pos = size - 1;
    }

    void prev() {
        if (curr == head) return;
        curr = curr->prev;
        --pos;
    }

    // allows traversal up to size position (n)
    void next() {
        if (curr == NULL) return;
        curr = curr->next;
        ++pos;
    }

    int length() { return size; }

    int currPos() { return pos; }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos < size);

        if (this->pos == size) {
            if (pos < size / 2) {
                // traverse right from head
                moveToStart();
                while (this->pos != pos) next();
            }
            else {
                // traverse left from tail
                moveToEnd();
                while (this->pos != pos) prev();
            }
        }

        else if (pos < this->pos) {
            if (pos + 1 < this->pos - pos) {
                // traverse right from head
                moveToStart();
                while (this->pos != pos) next();
            }
            else {
                // traverse left from curr
                while (this->pos != pos) prev();
            }
        }
        else {
            if (size - pos < pos - this->pos) {
                // traverse left from tail
                moveToEnd();
                while (this->pos != pos) prev();
            }
            else {
                // traverse right from curr
                while (this->pos != pos) next();
            }
        }
        assert(pos == this->pos);
    }

    E getValue() {
        assert(curr != NULL);
        return curr->val;
    }

    // returns the position of the element item or -1 if not found
    int Search(const E &item) {
        Node *tmp = head;
        for (int i = 0; tmp != NULL; i++) {
            if (tmp->val == item) {
                assert(i >= 0 && i < size);
                return i;
            }
        }
        return -1;
    }
};
