#include <iostream>
#include "LL.cpp"
#include "Arr.cpp"

#define TRANSPORT_NUMBER 3

using namespace std;

void printTransports(List<int> **transports, int k) {
    bool flag = true;
    for (int i = 0; i < TRANSPORT_NUMBER; i++) {
        flag = true;
        for (int j = 0; j < k; j++) {
            if (transports[i]->Search(j) != -1) {
                if (flag) {
                    flag = false;
                    cout << j;
                }
                else {
                    cout << "," << j;
                }
            }
            else {
                cout << ",";
            }
        }
        cout << "\n";
    }
}

int main() {
    List<int> **transports = new List<int>*[TRANSPORT_NUMBER]; // {Rickshaw, Bus, Train}
    for (int i = 0; i < TRANSPORT_NUMBER; i++) {
        transports[i] = new Arr<int>;
    }

    // Take initial input
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        transports[0]->append(i);
    }
    for (int i = 1; i < TRANSPORT_NUMBER; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int stop;
            cin >> stop;
            transports[i]->append(stop);
        }
    }

    int t;
    cin >> t;
    switch(t) {
        case 1:
            printTransports(transports, k);
            break;

        default:
            ;
    }

    for (int i = 0; i < TRANSPORT_NUMBER; i++) {
        transports[i]->clear();
        delete transports[i];
    }
    delete[] transports;
    return 0;
}
