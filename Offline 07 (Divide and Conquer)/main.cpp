#include<iostream>
#include<ctime>
#include<algorithm>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quicksort.h"

using namespace std;

int main() {
    srand(1);
    int n[] = {5, 10, 100, 1000, 10000, 100000};
    cout << ",Time required in ms,,,,,,\n";
    cout << "n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with Sorted Imput,Randomized Quicksort with Sorted Imput,STL sort() function\n";
    for (int i = 0; i < 6; i++) {
        cout << n[i];
        vector<int> a(n[i]);
        for (int j = 0; j < n[i]; j++) {
            a[j] = rand();
        }
        vector<int> b = a;
        clock_t start = clock();
        merge_sort(b);
        double time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        b = a;
        start = clock();
        quicksort(b, false);
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        b = a;
        start = clock();
        quicksort(b);
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        b = a;
        start = clock();
        insertion_sort(b);
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        start = clock();
        quicksort(b, false);
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        start = clock();
        quicksort(b);
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;

        b = a;
        start = clock();
        sort(b.begin(), b.end());
        time = (double)(clock() - start) / CLOCKS_PER_SEC;
        cout << ',' << time;
        cout << '\n';
    }
    return 0;
}
