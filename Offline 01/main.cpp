#include<iostream>
#include "LL.cpp"
#include "Arr.cpp"

using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
//    LinkedList<int> foo;
    Array<int> foo;
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
//        foo.printList();
        foo.append(val);
    }
//    foo.printList();
//    LinkedList<int> L(foo);
    Array<int> L(foo);
    L.printList();

    int q, p;
    while (true) {
        cin >> q >> p;
        if (q == 0) break;
        switch(q) {
            case 1:
                L.clear();
                cout << -1 << "\n";
                break;
            case 2:
                L.insert(p);
                cout << -1 << "\n";
                break;
            case 3:
                L.append(p);
                cout << -1 << "\n";
                break;
            case 4:
                cout << L.remove() << "\n";
                break;
            case 5:
                L.moveToStart();
                cout << -1 << "\n";
                break;
            case 6:
                L.moveToEnd();
                cout << -1 << "\n";
                break;
            case 7:
                L.prev();
                cout << -1 << "\n";
                break;
            case 8:
                L.next();
                cout << -1 << "\n";
                break;
            case 9:
                cout << L.length() << "\n";
                break;
            case 10:
                cout << L.currPos() << "\n";
                break;
            case 11:
                L.moveToPos(p);
                cout << -1 << "\n";
                break;
            case 12:
                cout << L.getValue() << "\n";
                break;
            case 13:
                cout << L.Search(p) << "\n";
                break;
            default:
                ;
        }
        L.printList();
    }

    return 0;
}
