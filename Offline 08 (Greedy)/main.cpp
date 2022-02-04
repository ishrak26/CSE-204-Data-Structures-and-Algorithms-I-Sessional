#include<iostream>
//#include<algorithm>
#include "quicksort_descending.h"

using namespace std;

// returns minimum cost to buy n flowers by k people
long long compute_min_cost(long long *arr, int n, int k) {
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += (i/k + 1) * arr[i];
    }
    return cost;
}

int main() {
    int n, k;
    cin >> n >> k;
    long long *plants = new long long[n];
    for (int i = 0; i < n; i++) cin >> plants[i];
//    sort(plants, plants+n, greater<long long>());
    quicksort_descending(plants, 0, n-1);
    long long cost = compute_min_cost(plants, n, k);
    delete[] plants;
    cout << cost << '\n';
    return 0;
}

// Proof of correctness:
// Let a_1, a_2, a_3, ..., a_n be the array of plant cost, sorted in descending order of values i.e. a_i >= a_i+1
// and b_1, b_2, b_3, ..., b_n be the factor by which each plant price is multiplied, where b_i <= b_i+1
// Our claim is, minimum cost will be a_1 * b_1 + a_2 * b_2 + ... + a_n * b_n = c
//
// For the sake of contradiction, let us suppose c is not the minimum cost, and there exists a cost c_1, where c_1 < c
// To obtain c_1, we multiply a_x with b_y and a_y with b_x, where x < y, a_x > a_y
// and b_x <= b_y or, b_x + m = b_y (m >= 0)
// Therefore, now the cost, c_1 is
// c_1 = c - (a_x * b_x + a_y * b_y) + (a_x * b_y + a_y * b_x)
// or, c_1 = c - (a_x * b_x + a_y * b_y) + (a_x * (b_x + m) + a_y * (b_y - m))
// or, c_1 = c + m * (a_x - a_y)
//
// Now, c_1 = c when m = 0 or, b_x = b_y, which was already our claimed minimum cost
// and, c_1 > c when m > 0 i.e. b_x != b_y
// Therefore, there exists no pair of indices x and y for which c_1 < c
// Hence, c is the minimum cost
//
// Now, allowable values for b_i are b_i = 1, 2, 3, ...
// where, we have k 1's, k 2's, k 3's and so on to choose from
// To find b_1, b_2, ..., b_n in ascending order of values, and keep it as minimum as possible, we order it as
// b_1 = b_2 = b_3 = ... = b_k = 1
// b_k+1 = b_k+2 = ...= b_2k = 2 and so on up to n,
// which gives us the optimal solution i.e. the minimum cost (QED)
