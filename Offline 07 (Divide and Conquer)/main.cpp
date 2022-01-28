#include<iostream>
#include<ctime>
#include<algorithm>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quicksort.h"

using namespace std;

int main() {
    freopen("out.csv", "w", stdout);
    srand(1);
    int n[] = {5, 10, 100, 1000, 10000, 100000};
    cout << ",Time required in ms,,,,,,\n";
    cout << "n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with Sorted Imput,Randomized Quicksort with Sorted Imput,STL sort() function\n";

    double times[7];
    for (int i = 0; i < 6; i++) {

        for (int k = 0; k < 7; k++) {
            times[k] = 0;
        }

        cout << n[i];
        vector<int> a(n[i]), b;

        for (int k = 0; k < 20; k++) {
            for (int j = 0; j < n[i]; j++) {
                a[j] = rand();
            }
            b = a;
            clock_t start = clock();
            merge_sort(b);
            double time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[0] += time;

            b = a;
            start = clock();
            quicksort(b, false);
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[1] += time;

            b = a;
            start = clock();
            quicksort(b);
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[2] += time;

            b = a;
            start = clock();
            insertion_sort(b);
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[3] += time;

            start = clock();
            quicksort(b, false);
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[4] += time;

            start = clock();
            quicksort(b);
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[5] += time;

            b = a;
            start = clock();
            sort(b.begin(), b.end());
            time = (double)(clock() - start) / CLOCKS_PER_SEC;
            times[6] += time;
        }
        for (int k = 0; k < 7; k++) {
            times[k] /= 20;
            times[k] *= 1000;
            cout << ',' << times[k];
        }
        cout << '\n';
    }
    return 0;
}
