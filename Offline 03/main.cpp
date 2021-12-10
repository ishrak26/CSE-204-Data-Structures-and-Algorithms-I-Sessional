#include <iostream>
#include <assert.h>
#include "ArrQueue.cpp"
#include "LLQueue.cpp"

using namespace std;

template <typename E>
void printQueue(Queue<E> *q) {
    ArrQueue<E> cpy;
    cout << '<';
    int sz = q->length();
    for (int i = 0; i < sz; i++) {
        cpy.enqueue(q->dequeue());
        cout << " " << cpy.rearValue();
        q->enqueue(cpy.rearValue());
    }
    assert(q->length() == sz);
    cout << " >\n";
}

int main() {
    int n;
    cin >> n;
    ArrQueue<int> tmp(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tmp.enqueue(val);
    }

    ArrQueue<int> ob(&tmp);
//    LLQueue<int> ob(&tmp);
    printQueue(&ob);

    int p, q, ret;
    while (true) {
        cin >> p >> q;
        if (p == 0) break;

        ret = -1;
        switch(p) {
            case 1:
                ob.clear();
                break;
            case 2:
                ob.enqueue(q);
                break;
            case 3:
                ret = ob.dequeue();
                break;
            case 4:
                ret = ob.length();
                break;
            case 5:
                ret = ob.frontValue();
                break;
            case 6:
                ret = ob.rearValue();
                break;
            case 7:
                ret = ob.leaveQueue();
                break;
            default:
                cout << "Invalid input\n";
        }

        printQueue(&ob);
        cout << ret << "\n";
    }
    return 0;
}
