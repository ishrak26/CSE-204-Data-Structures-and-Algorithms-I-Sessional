#include<iostream>
#include "LL.cpp"
#include "Arr.cpp"

using namespace std;

void printList(List<int> *L) {
    int pos = L->currPos();
    cout << "<";
    for (L->moveToStart(); L->currPos() < pos; L->next()) {
        cout << L->getValue() << " ";
    }
    if (L->length() > 0) cout << "|";
    for (; L->currPos() < L->length(); L->next()) {
        cout << " " << L->getValue();
    }
    cout << ">\n";
}

int main() {
    int k, x;
    cin >> k >> x;
    List<int> *L;
//    LinkedList<int> foo;
    Array<int> foo;
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
        foo.append(val);
    }
//  L = new LinkedList<int> (foo);
    L = new Array<int> (foo);
    int pos = L->currPos();
    printList(L);
    L->moveToPos(pos);

    int q, p, ret;
    while (true) {
        cin >> q >> p;
        if (q == 0) break;

        ret = -1;

        switch(q) {
            case 1:
                L->clear();
                break;
            case 2:
                L->insert(p);
                break;
            case 3:
                L->append(p);
                break;
            case 4:
                ret =  L->remove();
                break;
            case 5:
                L->moveToStart();
                break;
            case 6:
                L->moveToEnd();
                break;
            case 7:
                L->prev();
                break;
            case 8:
                L->next();
                break;
            case 9:
                ret = L->length();
                break;
            case 10:
                ret = L->currPos();
                break;
            case 11:
                L->moveToPos(p);
                break;
            case 12:
                ret = L->getValue();
                break;
            case 13:
                ret = L->Search(p);
                break;
            default:
                ;
        }

        pos = L->currPos();
        printList(L);
        L->moveToPos(pos);
        cout << ret << "\n";
    }

    delete L;
    return 0;
}
