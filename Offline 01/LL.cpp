#include <iostream>
#include <assert.h>
#include "List.h"

using namespace std;

template <typename E>
class LinkedList : public List<E> {
    class Node {
    public:
        E val;
        Node *next;

        Node(const E &val, Node *next = NULL) {
            this->val = val;
            this->next = next;
        }
    };

    Node *head;
    Node *tail;
    Node *curr;
    int size;
    int pos;

    void init() {
        head = new Node(-1);
        tail = head;
        curr = head;
        size = 0;
        pos = 0;
    }

    void removeCurr() {
        if (curr->next == NULL) return;
        if (curr->next == tail) tail = curr;
        Node *tmp = curr->next->next;
        delete curr->next;
        curr->next = tmp;
        --size;
    }

public:
    LinkedList() {
        init();
    }

    LinkedList(LinkedList &L) {
        init();
        for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
            append(L.getValue());
        }
    }

    ~LinkedList() {
        clear();
        delete head;
    }

    void clear() {
        moveToStart();
        while (tail != head) removeCurr();
    }

    void insert(const E &item) {
        Node *tmp = new Node(item, curr->next);
        curr->next = tmp;
        if (curr == tail) tail = tail->next;
        ++size;
    }

    void append(const E &item) {
        Node *tmp = new Node(item);
        tail->next = tmp;
        tail = tail->next;
        ++size;
    }

    // Remove and return the current element
    E remove() {
        assert(curr->next != NULL);
        E item = curr->next->val;
        removeCurr();
        return item;
    }

    void moveToStart() {
        curr = head;
        pos = 0;
    }

    void moveToEnd() {
        curr = tail;
        pos = size;
    }

    void prev() {
        if (curr == head) return;
        Node *tmp = head;
        while (tmp->next != curr) {
            tmp = tmp->next;
        }
        curr = tmp;
        --pos;
    }

    void next() {
        if (curr->next == NULL) return;
        curr = curr->next;
        ++pos;
    }

    int length() { return size; }

    int currPos() {
        return pos;
    }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos <= size);
        if (pos < this->pos) moveToStart();
        else pos -= this->pos;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
            ++this->pos;
        }
    }

    E getValue() {
        assert(curr->next != NULL);
        return curr->next->val;
    }

    // returns the position of the element item or -1 if not found
    int Search(const E &item) {
        Node *tmp = head->next;
        for (int i = 0; tmp->next != NULL; i++) {
            if (tmp->val == item) return i;
            tmp = tmp->next;
        }
        return -1;
    }

    void printList() {
        Node *tmp = head->next;
        while (tmp != curr->next) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << "|";
        while (tmp != NULL) {
            cout << " " << tmp->val;
            tmp = tmp->next;
        }
        cout << "\n";
    }
};
