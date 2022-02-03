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

// Proof of correctness
// Let a_1, a_2, a_3, ..., a_n be the array of plant cost, sorted in descending order i.e. a_i >= a_i+1
// and b_1, b_2, b_3, ..., b_n be the factor by which each plant price is multiplied, where b_i <= b_i+1
// Our claim is, minimum cost will be a_1 * b_1 + a_2 * b_2 + ... + a_n * b_n = c

// For the sake of contradiction, let us swap b_x with b_y , where x < y and a_x > a_y
// Since x < y, b_x <= b_y or, b_x + m = b_y (m >= 0)
// Therefore, now the cost is
// c_1 = c - (a_x * b_x + a_y * b_y) + (a_x * b_y + a_y * b_x)
// or, c_1 = c - (a_x * b_x + a_y * b_y) + (a_x * (b_x + m) + a_y * (b_y - m))
// or, c_1 = c + m * (a_x - a_y)

// Now, c_1 = c when m = 0 or, b_x = b_y, which is already our optimal solution
// and, c_1 > c when m > 0 i.e. b_x != b_y
// Hence, c is the minimum cost (Proved)


