#include<iostream>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quicksort.h"

using namespace std;

void print_vector(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i <  n; i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    srand(1);
    int n = 100000;

    for (int i = 0; i < 5; i++) {
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            v[j] = rand();
//            v[j] = 23;
        }
//        v[2] = v[9] = 17;
//        print_vector(v);
//        insertion_sort(v);
        merge_sort(v);
//        quicksort(v, false);
//        print_vector(v);
//        cout << '\n';
    }
    return 0;
}
