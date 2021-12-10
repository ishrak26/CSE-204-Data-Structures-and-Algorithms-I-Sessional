#include <assert.h>
#include "Queue.h"

using namespace std;

#define DEFAULT_SIZE 1

template <typename E>
class ArrQueue: public Queue<E> {
    E *arr;
    int front;
    int rear;
    int capacity;
    int len;

    void init(int cap = DEFAULT_SIZE) {
        capacity = cap;
        arr = new E[capacity];
        len = 0;
    }

    void resize() {
        capacity <<= 1;
        E *newArr = new E[capacity];
        for (int i = 0; i < len; i++) {
            newArr[i] = arr[front];
            front = (front + 1) % len; // arr is full, so len = prev_capacity
        }
        delete[] arr;
        arr = newArr;
        front = 0;
        rear = len - 1;
    }

    inline bool isEmpty() { return len == 0; }

    inline bool isFull() { return len == capacity; }

public:
    ArrQueue(int x = DEFAULT_SIZE) {
        init(x);
    }

    ArrQueue(Queue<E> *q) {
        int sz = q->length();
        init();
        for (int i = 0; i < sz; i++) {
            enqueue(q->dequeue());
            q->enqueue(rearValue());
        }
        assert(q->length() == sz);
    }

    ~ArrQueue() {
        delete[] arr;
    }

    void clear() {
        delete[] arr;
        init();
    }

    // append at rear
    void enqueue(const E item) {
        if (isEmpty()) {
            // insert at 0-th position
            arr[0] = item;
            front = rear = 0;
            ++len;
            return;
        }
        if (isFull())
            resize();
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        ++len;
    }

    // remove from front
    E dequeue() {
        assert(!isEmpty());
        E ret = arr[front];
        front = (front + 1) % capacity;
        --len;
        return ret;
    }

    int length() const { return len; }

    E frontValue() {
        assert(!isEmpty());
        return arr[front];
    }

    E rearValue() {
        assert(!isEmpty());
        return arr[rear];
    }

    // remove from rear
    E leaveQueue() {
        assert(!isEmpty());
        E ret = arr[rear];
        --rear;
        if (rear < 0) rear += capacity;
        --len;
        return ret;
    }
};
