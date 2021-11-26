#include <iostream>
#include "LL.cpp"
#include "Arr.cpp"

using namespace std;

class test {
    int var;
    int var2;
public:
    test() {
        var = -1;
        var2 = -2;
    }
    test(int var) {
        this->var = var;
        this->var2 = -2;
    }

    int operator==(test ob) {
        return var == ob.var && var2 == ob.var2;
    }

    friend ostream &operator<<(ostream &stream, test ob);
};

ostream &operator<<(ostream &stream, test ob) {
    stream << "(" << ob.var << ", " << ob.var2 << ")";
    return stream;
}

template <typename E>
void printList(List<E> *L) {
    if (L->length() == 0) {
        cout << "<>\n";
        return;
    }
    cerr << "len is " << L->length() << "\n";
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
    L->moveToPos(pos);
}

int main() {
    int k, x;
    cin >> k >> x;
    List<test> *L;
////    LL<int> foo;
    Arr<test> foo;
    for (int i = 0; i < k; i++) {
        int val;
        cin >> val;
        test ob(val);
        foo.append(ob);
    }
////    LL<int> ob(&foo);
    Arr<test> ob(&foo);
//
    L = &ob;
//
    cerr << "ob created successfully\n";
    printList(L);
//
//    int q, p, ret;
//    while (true) {
//        cin >> q >> p;
//        if (q == 0) break;
//
//        ret = -1;
//
//        switch(q) {
//            case 1:
//                L->clear();
//                break;
//            case 2:
//                L->insert(p);
//                break;
//            case 3:
//                L->append(p);
//                break;
//            case 4:
//                ret =  L->remove();
//                break;
//            case 5:
//                L->moveToStart();
//                break;
//            case 6:
//                L->moveToEnd();
//                break;
//            case 7:
//                L->prev();
//                break;
//            case 8:
//                L->next();
//                break;
//            case 9:
//                ret = L->length();
//                break;
//            case 10:
//                ret = L->currPos();
//                break;
//            case 11:
//                L->moveToPos(p);
//                break;
//            case 12:
//                ret = L->getValue();
//                break;
//            case 13:
//                ret = L->Search(p);
//                break;
//            default:
//                cout << "Invalid Input\n";
//        }
//
//        printList(L);
//
//        cout << ret << "\n";
//    }

    return 0;
}
