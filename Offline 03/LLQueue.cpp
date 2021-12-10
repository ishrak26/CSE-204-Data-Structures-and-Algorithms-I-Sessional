#include "Queue.h"

using namespace std;

template <typename E>
class LLQueue: public Queue<E> {
    class Node {
        E val;
        Node *prev;
        Node *next;

    public:
        Node(E val, Node *prev = NULL, Node *next = NULL) {
            this->val = val;
            this->prev = prev;
            this->next = next;
        }

    };

    Node *front;
    Node *rear;
    int len;

public:
    LLQueue() {
        front = rear = NULL;
        len = 0;
    }

    LLQueue(Queue<E> &q) {
        int sz = q.length();
        for (int i = 0; i < sz; i++) {
            enqueue(q.dequeue());
            q.enqueue(rearValue());
        }
        assert(q.size() == sz);
    }

    ~LLQueue() {
        clear();
    }

    void clear() {
        while (len) dequeue();
    }

    void enqueue(const E item) {
        // add item to rear of the list
        if (len == 0) {
            // empty list
            front = rear = new Node(item);
        }
        else {
            rear->next = new Node(item, rear, NULL);
            rear = rear->next;
        }
        ++len;
    }

    /// HANDLE 1 ELEMENT LIST
    E dequeue() {
        // remove from front
        assert(len > 0); // front is not null
        E ret = front->val;
        front = front->next;
        delete front->prev;
        front->prev = NULL;
        --len;
        return ret;
    }

    int length() const {
        return len;
    }

    E frontValue() const {
        assert(len > 0); // front is not null
        return front->val;
    }

    E rearValue() const {
        assert(len > 0); // rear is not null
        return rear->val;
    }

    E leaveQueue() {
        // remove from rear
        assert(len > 0); // rear is not null
        E ret = rear->val;
        rear = rear->prev;
        delete rear->next;
        rear->next = NULL;
        --len;
        return ret;
    }
};
