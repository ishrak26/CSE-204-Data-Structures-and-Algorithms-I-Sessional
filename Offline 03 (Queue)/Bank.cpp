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
        t1 = 0;
        t2 = 0;
    }

    void enter_queue(int t) {
        assert(q1->length() && q2->length()); // neither queue is empty
        if (q1->length() <= q2->length()) {
            // stand at booth 1 queue
            q1->enqueue(t);
        }
        else {
            // stand at booth 2 queue
            q2->enqueue(t);
        }
    }

    void leave_queue(int num) {
        assert(num == 1 || num == 2);
        if (num == 1) {
            assert(q1->length());
            q1->dequeue();
            if (q1->length()) {
                t1 += q1->frontValue();
            }
        }
        else {
            assert(q2->length());
            q2->dequeue();
            if (q2->length()) {
                t2 += q2->frontValue();
            }
        }
    }

    void check_queue_switch() {
        while (q1->length() - q2->length() >= 2) {
            // switch from q1 to q2
            if (!q2->length()) {
                q2->enqueue(q1->rearValue());
                t2 += q1->leaveQueue();
            }
            else enter_queue(q1->leaveQueue());
        }
        while (q2->length() - q1->length() >= 2) {
            // switch from q2 to q1
            if (!q1->length()) {
                q1->enqueue(q2->rearValue());
                t1 += q2->leaveQueue();
            }
            else enter_queue(q2->leaveQueue());
        }
    }

    void addhelp(int s, int t) {
        // check if any queue is empty
        if (!q1->length() || !q2->length()) {
            if (!q1->length()) {
                // go directly to the first booth
                q1->enqueue(t);
                t1 = max(t1, s) + t;
            }
            else if (!q2->length()) {
                // go directly to the second booth
                q2->enqueue(t);
                t2 = max(t2, s) + t;
            }
            return;
        }

        // check if any time is distinctly minimum
        if (s < t1 && s < t2) {
            // s is the nearest time
            enter_queue(t);
        }
        else if (t1 < s && t1 < t2) {
            // t1 is the nearest time
            leave_queue(1);
            check_queue_switch();
            addhelp(s, t);
        }
        else if (t2 < s && t2 < t1) {
            // t2 is the nearest time
            leave_queue(2);
            check_queue_switch();
            addhelp(s, t);
        }
        else {
            // at least two values are equal
            if (s == t1 && s < t2) {
                // handle t1 first
                leave_queue(1);
                addhelp(s, t);
            }
            else if (s == t2 && s < t1) {
                // handle t2 first
                leave_queue(2);
                addhelp(s, t);
            }
            else if (t1 == t2 && t1 < s) {
                leave_queue(1);
                leave_queue(2);
                check_queue_switch();
                addhelp(s, t);
            }
            else {
                // all three are equal
                leave_queue(1);
                leave_queue(2);
                addhelp(s, t);
            }
        }
    }

    void endhelp() {
        while (q1->length() || q2->length()) {
            if (!q1->length()) {
                // consider only q2
                while (q2->length()) {
                    leave_queue(2);
                    check_queue_switch();
                }
            }
            else if (!q2->length()) {
                // consider only q1
                while (q1->length()) {
                    leave_queue(1);
                    check_queue_switch();
                }
            }
            else {
                // consider both
                // neither is empty
                if (t1 < t2) {
                    leave_queue(1);
                    check_queue_switch();
                }
                else if (t1 > t2) {
                    leave_queue(2);
                    check_queue_switch();
                }
                else {
                    leave_queue(1);
                    leave_queue(2);
                    check_queue_switch();
                }
            }
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
        addhelp(s, t);
    }

    void end_queue() {
        endhelp();
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
        ob.add(s, t);
    }
    ob.end_queue();
    for (int i = 1; i <= 2; i++) {
        cout << "Booth " << i << " finishes service at " << "t=" << ob.booth_end_time(i) << "\n";
    }

    return 0;
}
