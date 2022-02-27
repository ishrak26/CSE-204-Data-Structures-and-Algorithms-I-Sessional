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

        Node(Node *next = NULL, Node *prev = NULL) {
            this->next = next;
            this->prev = prev;
        }

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
        head = tail = curr = new Node;
        size = 0;
        pos = 0;
    }

    // remove node pointed by curr
    void removeCurr() {
        assert(curr->next != NULL); // points to after last element

        if (curr->prev != NULL) { // not first element
            curr->prev->next = curr->next;
        }
        else {
            // curr is first element
            head = curr->next;
        }

        curr->next->prev = curr->prev;

        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
        --size;

        if (size == 0) {
            curr = tail = head;
        }
        else if (curr->next == NULL) {
            prev();
            tail = curr;
        }
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
        while (size) removeCurr();
    }

    void insert(const E &item) {
        if (size == 0) {
            append(item);
        }
        else {
            Node *tmp = new Node(item, curr, curr->prev);
            if (curr->prev == NULL) head = tmp;
            else curr->prev->next = tmp;

            if (curr->next == NULL) {
                tail->next = tmp;
                tail = tmp;
            }
            curr->prev = tmp;
            curr = tmp;
            ++size;
        }
    }

    void append(const E &item) {
        if (size == 0) {
            curr->prev = new Node(item, curr, NULL);
            head = tail = curr = curr->prev;
        }
        else {
            Node *tmp = new Node(item, tail->next, tail);
            tail->next->prev = tmp;
            tail->next = tmp;
            tail = tail->next;

        }
        ++size;
    }

    // Remove and return the current element
    E remove() {
        assert(curr->next != NULL);
        E item = curr->val;
        removeCurr();
        return item;
    }

    void moveToStart() {
        curr = head;
        pos = 0;
    }

    // point to last element
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
        if (curr->next == NULL) return;
        curr = curr->next;
        ++pos;
    }

    int length() { return size; }

    int currPos() { return pos; }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos <= size);

        if (pos < this->pos) {
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
                next();
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
        assert(curr->next != NULL); // curr points to after last element
        return curr->val;
    }

    // returns the position of the element item or -1 if not found
    int Search(const E &item) {
        int tmp = pos;
        int ret = -1;
        for (moveToStart(); pos < size; next()) {
            assert(curr != NULL);
            if (curr->val == item) {
                ret = pos;
                break;
            }
        }
        moveToPos(tmp);
        return ret;
    }
};
