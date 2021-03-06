#include <iostream>
#include "Arr.cpp"
#include "LL.cpp"

using namespace std;

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
    Arr<int> tmp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tmp.push(val);
    }

    Arr<int> ob(&tmp);
//    LL<int> ob(&tmp);
    print_stack(&ob);

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
                ob.push(q);
                break;
            case 3:
                ret = ob.pop();
                break;
            case 4:
                ret = ob.length();
                break;
            case 5:
                ret = ob.topValue();
                break;
            case 6:
                ob.setDirection(q);
                break;
            default:
                cout << "Invalid input\n";
        }
        print_stack(&ob);
        cout << ret << "\n";
    }
    return 0;
}
