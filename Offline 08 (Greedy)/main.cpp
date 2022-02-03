#include<iostream>
#include<algorithm>
#include "quicksort_descending.h"

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int *plants = new int[n];
    for (int i = 0; i < n; i++) cin >> plants[i];
//    sort(plants, plants+n, greater<int>());
    quicksort_descending(plants, 0, n-1);
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += (i/k + 1) * plants[i];
    }
    delete[] plants;
    cout << cost << '\n';
    return 0;
}
