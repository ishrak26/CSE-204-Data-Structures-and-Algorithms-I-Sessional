#include <iostream>
#include "LL.cpp"
#include "Arr.cpp"

using namespace std;

template<typename E>
class TNL {
    List<E> **transports;
    int transport_number;
    char implementation_type;

public:
    TNL(char implementation_type = 'A', int transport_number = 3) {
        assert(implementation_type == 'A' || implementation_type == 'L' || implementation_type == 'a'
               || implementation_type == 'l');
        assert(transport_number >= 0);
        if (implementation_type == 'a' || implementation_type == 'l') {
            implementation_type -= 32;
        }
        this->implementation_type = implementation_type;
        this->transport_number = transport_number;

        transports = new List<E>*[transport_number];
        for (int i = 0; i < transport_number; i++) {
            if (implementation_type == 'A') transports[i] = new Arr<E>;
            else transports[i] = new LL<E>;
        }
    }

    ~TNL() {
        for (int i = 0; i < transport_number; i++) {
            if (implementation_type == 'A') delete (Arr<E>*)transports[i];
            else delete (LL<E>*)transports[i];
        }
        delete[] transports;
    }

    void add(int transport, const E &item) {
        assert(transport >= 0 && transport < transport_number);
        transports[transport]->append(item);
    }

    void print(List<E> *L) {
        bool flag = true;
        for (int i = 0; i < transport_number; i++) {
            flag = true;
            int pos = L->currPos();
            for (L->moveToStart(); L->currPos() < L->length(); L->next()) {
                E item = L->getValue();
                if (transports[i]->Search(item) != -1) {
                    if (flag) {
                        flag = false;
                        cout << item;
                    }
                    else {
                        cout << "," << item;
                    }
                }
                else {
                    cout << ",";
                }
            }
            L->moveToPos(pos);
            cout << "\n";
        }
    }
};

int main() {
    int transport_number = 3;
    TNL<int> ob('L', transport_number);

    // Take initial input
    int k;
    cin >> k;
    Arr<int> L(k);
    for (int i = 0; i < k; i++) {
        L.append(i);
    }

    for (int i = 0; i < k; i++) {
        ob.add(0, i);
    }
    for (int i = 1; i < transport_number; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int stop;
            cin >> stop;
            ob.add(i, stop);
        }
    }

    int t;
    cin >> t;
    switch(t) {
        case 1:
            ob.print(&L);
            break;

        default:
            cout << "Invalid Input\n";
    }

    return 0;
}
