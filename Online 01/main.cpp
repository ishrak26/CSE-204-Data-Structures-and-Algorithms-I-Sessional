#include <iostream>
#include "LL.cpp"
#include "Arr.cpp"

using namespace std;

void printList(List<int> *L) {
    if (L->length() == 0) {
        cout << "<>\n";
        return;
    }
    int pos = L->currPos();
    cerr << "pos before is " << pos << "\n";
    cout << "<";
    L->moveToStart();
    for (int i = 0; i < pos; i++) {
        cout << L->getValue() << " ";
        L->next();
    }
    cout << "|";
    for (int i = pos; i < L->length(); i++) {
        cout << " " << L->getValue();
        L->next();
    }
    cout << ">\n";
    L->moveToPos(pos);
    cerr << "pos after is " << L->currPos() << "\n";
}

int main() {
    int k, x;
    cin >> k >> x;
    List<int> *L;
    LL<int> foo;
//    Arr<int> foo;
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
        foo.append(val);
//        cerr << "main\n";
    }

    cerr << "appended successfully\n";
//    cerr << foo.getValue() << "\n";
//    foo.next();
//    cerr << "next ok\n";
//    cerr << foo.currPos() << "\n";
//    cerr << "currPos ok\n";
//    cerr << foo.getValue() << "\n";
//    cerr << "foo " << foo.getValue() << "\n";
//    exit(1);

    LL<int> ob(&foo);
//    cerr << "len is " << ob.length() << "\n";
//    exit(1);
//    cout << ob.getValue();
//    for (int i = 0; i < ob.length(); i++) {
//        cout << ob.getValue() << "\n";
//        ob.next();
//    }
//    printList(&ob);
//    cerr << "list printed\n";
//    return 1;
//    Arr<int> ob(&foo);

    L = &ob;

    printList(L);

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
                cout << "Invalid Input\n";
        }

        printList(L);

        cout << ret << "\n";
    }

    return 0;
}
