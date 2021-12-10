#include <iostream>
#include "ArrQueue.cpp"
#include "LLQueue.cpp"

using namespace std;

class Bank {
    // both the queues will store only service time information
    Queue<int> *q1;
    Queue<int> *q2;

    int t1; // current end time of the first queue
    int t2; // current end time of the second queue

    char implementation;

    void init() {
        if (implementation == 'A') {
            q1 = new ArrQueue<int>;
            q2 = new ArrQueue<int>;
        }
        else {
            q1 = new LLQueue<int>;
            q2 = new LLQueue<int>;
        }
    }

    void add_to_queue(int t) {
        if (q1->length() <= q2->length()) {
            // add to q1
            q1->enqueue(t);
        }
        else {
            // add to q2
            q2->enqueue(t);
        }
    }

    void dequeue(int num) {
        assert(num == 1 || num == 2);
        if (num == 1) {
            // next customer from the queue 1 will receive service
            assert(q1->length());
            q1->dequeue();
            t1 += q1->frontValue();

        }
    }

public:
    Bank(char implementation = 'A') {
        assert(implementation == 'A' || implementation == 'L');
        this->implementation = implementation;
        init();
    }

    ~Bank() {
        if (implementation == 'A') {
            delete (ArrQueue<int>*) q1;
            delete (ArrQueue<int>*) q2;
        }
        else {
            delete (LLQueue<int>*) q1;
            delete (LLQueue<int>*) q2;
        }
    }

    void add(int s, int t) {
        if (s < t1 && s < t2) {
            // new customer will have to enter either of the queues
            add_to_queue(t);
        }
        else {
            // dequeue will occur first
            while (t1 <= s || t2 <= s) {
                if (q1->length() == 0) {
                    // consider only q2 to dequeue
                    while (t2 <= s) {

                    }
                }
                if (t1 <= t2) {

                }
            }
        }
    }

    int booth_end_time(int num) {
        assert(num == 1 || num == 2);
        if (num == 1) return t1;
        return t2;
    }
};

int main() {
    Bank ob('A');
    int n, s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;

    }

    for (int i = 1; i <= 2; i++) {
        cout << "Booth " << i << " finishes service at " << "t=" << ob.booth_end_time(i) << "\n";
    }

    return 0;
}
