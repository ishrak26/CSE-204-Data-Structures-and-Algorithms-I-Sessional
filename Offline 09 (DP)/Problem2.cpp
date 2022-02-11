#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

// dp state computation function
int func_dp(int pos, int mask, vector<vector<int>>& dp, const vector<vector<int>>& v, int n) {
    assert(pos >= 0 && pos < n);
    assert(mask >= 0 && mask < (1<<n));
    if (dp[pos][mask] != -1) // dp state already computed
        return dp[pos][mask];
    int cost = 0, mi = 1<<30;;
    for (int i = 0; i < n; i++) {
        if (mask & (1<<i)) { // i-th city already visited
            cost += v[pos][i]; // add the already visited cost
        }
        else {
            mi = min(mi, func_dp(i, mask | (1<<i), dp, v, n)); // visit i-th city next
        }
    }
    if (mi < (1<<30)) cost += mi; // there has been at least a new visit
    return dp[pos][mask] = cost;
}

// computes the minimum cost to travel all n cities starting from any
int find_min_cost(int n, vector<vector<int>>& dp, const vector<vector<int>>& v) { // O(n^2 * 2^n)
    int mask = 0;
    int min_cost = 1<<30;
    // find which city to start from
    for (int i = 0; i < n; i++) {
        min_cost = min(min_cost, func_dp(i, mask | (1<<i), dp, v, n)); // Total (n * 2^n) dp states
    }
    return min_cost;
}

// backtracks and prints the cities visited in the exact order so as to minimize the cost
void backtrack(const vector<vector<int>>& dp, int n) {
    int mask = 0;
    for (int i = 0; i < n; i++) {
        int mi = 1<<30;
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (mask & (1<<j)) continue;
            if (dp[j][mask | (1<<j)] < mi) {
                mi = dp[j][mask | (1<<j)];
                idx = j;
            }
        }
        assert(idx != -1);
        if (i > 0) cout << "-> ";
        cout << idx+1 << ' ';
        mask |= (1<<idx);
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    vector<vector<int>> dp(n, vector<int> (1<<n, -1));
    // dp[i][j] implies remaining cost to visit all cities starting from i-th city with given state j

    int cost = find_min_cost(n, dp, v);
    cout << cost << '\n';

    // backtrack(dp, n);
    return 0;
}
