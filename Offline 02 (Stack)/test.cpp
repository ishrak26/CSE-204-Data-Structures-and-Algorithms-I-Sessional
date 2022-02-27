#include <iostream>
#include "Arr.cpp"
#include "LL.cpp"

using namespace std;

class test {
    int fi, se;
public:
    test() {
        fi = 7;
        se = 13;
    }
    test(int fi, int se) {
        this->fi = fi;
        this->se = se;
    }
    friend ostream &operator<<(ostream &str, test ob) {
        str << '(' << ob.fi << ", " << ob.se << ')';
        return str;
    }
    friend istream &operator>>(istream &str, test &ob) {
        str >> ob.fi >> ob.se;
        return str;
    }
    test operator=(const test &ob) {
        this->fi = ob.fi;
        this->se = ob.se;
        return *this;
    }
};

template <typename E>
void print_stack(Stack<E> *s) {
    Arr<E> tmp;
    while (s->length()) {
        tmp.push(s->pop());
    }
    cout << "< ";
    while (tmp.length()) {
        cout << tmp.topValue() << " ";
        s->push(tmp.pop());
    }
    cout << ">\n";
}

int main() {
    Arr<test> tmp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test ob;
        cin >> ob;
        tmp.push(ob);
    }

    Arr<test> ob(&tmp);
//    LL<test> ob(&tmp);
    print_stack(&ob);

    int p, ret;
    test q, item;
    while (true) {
        cin >> p >> q;
        if (p == 0) break;

        switch(p) {
            case 1:
                ob.clear();
                break;
            case 2:
                ob.push(q);
                break;
            case 3:
                item = ob.pop();
                break;
            case 4:
                ret = ob.length();
                break;
            case 5:
                item = ob.topValue();
                break;
//            case 6:
//                ob.setDirection(q);
//                break;
            default:
                cout << "Invalid input\n";
        }
        print_stack(&ob);
        cout << ret << " " << item << "\n";
    }
    return 0;
}

