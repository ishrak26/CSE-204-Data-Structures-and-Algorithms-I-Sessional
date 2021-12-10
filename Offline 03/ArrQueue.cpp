#include "Queue.h"

using namespace std;

template <typename E>
class ArrQueue: public Queue<E> {
    E *arr;
    int front;
    int rear;
    int capacity;

public:
    ArrQueue() {

    }

    ArrQueue(Queue<E> &q) {
        int sz = q.length();
        for (int i = 0; i < sz; i++) {
            enqueue(q.dequeue());
            q.enqueue(rearValue());
        }
        assert(q.size() == sz);
    }

    ~ArrQueue() {

    }

    void clear() {

    }

    void enqueue(const E item) {

    }

    E dequeue() {

    }

    int length() const {

    }

    E frontValue() const {

    }

    E rearValue() const {

    }

    E leaveQueue() {

    }
};
