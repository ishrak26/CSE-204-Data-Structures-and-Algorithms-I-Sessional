#include <assert.h>
#include "Queue.h"

using namespace std;

template <typename E>
class LLQueue: public Queue<E> {
    class Node {
    public:
        E val;
        Node *prev;
        Node *next;

        Node(E val, Node *prev = NULL, Node *next = NULL) {
            this->val = val;
            this->prev = prev;
            this->next = next;
        }

    };

    Node *front;
    Node *rear;
    int len;

    inline bool isEmpty() { return len == 0; }

public:
    LLQueue() {
        front = rear = NULL;
        len = 0;
    }

    LLQueue(Queue<E> *q) {
        len = 0;
        int sz = q->length();
        for (int i = 0; i < sz; i++) {
            enqueue(q->dequeue());
            q->enqueue(rearValue());
        }
        assert(q->length() == sz);
    }

    ~LLQueue() {
        clear();
    }

    void clear() {
        while (len) dequeue();
    }

    // append at rear
    void enqueue(const E item) {
        // add item to rear of the list
        if (isEmpty()) {
            // empty list
            front = rear = new Node(item);
        }
        else {
            rear->next = new Node(item, rear, NULL);
            rear = rear->next;
        }
        ++len;
    }

    // remove from front
    E dequeue() {
        assert(!isEmpty()); // front is not null

        E ret = front->val;
        Node *tmp = front;
        front = front->next;
        delete tmp;
        --len;

        if (isEmpty()) {
            rear = front; // NULL
        }
        else {
            front->prev = NULL;
        }

        return ret;
    }

    int length() const {
        return len;
    }

    E frontValue() {
        assert(!isEmpty()); // front is not null
        return front->val;
    }

    E rearValue() {
        assert(!isEmpty()); // rear is not null
        return rear->val;
    }

    // remove from rear
    E leaveQueue() {
        assert(!isEmpty()); // rear is not null

        E ret = rear->val;
        Node *tmp = rear;
        rear = rear->prev;
        delete tmp;
        --len;

        if (isEmpty()) {
            front = rear; // NULL
        }
        else {
            rear->next = NULL;
        }

        return ret;
    }
};
