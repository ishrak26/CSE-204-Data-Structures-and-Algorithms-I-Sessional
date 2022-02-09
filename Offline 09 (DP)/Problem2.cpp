#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int func_dp(int pos, int mask, vector<vector<int>>& dp, const vector<vector<int>>& v, int n) {
    assert(pos >= 0 && pos < n);
    assert(mask >= 0 && mask < (1<<n));
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int cost = 0, mi = 1<<30;;
    for (int i = 0; i < n; i++) {
        if (mask & (1<<i)) {
            cost += v[pos][i];
        }
        else {
            mi = min(mi, func_dp(i, mask | (1<<i), dp, v, n)); // visit i-th city next
        }
    }
    if (mi < (1<<30)) cost += mi;
    return dp[pos][mask] = cost;
}

int find_min_cost(int n, vector<vector<int>>& dp, const vector<vector<int>>& v) {
    int mask = 0;
    int min_cost = 1<<30;
    // find which city to start from
    for (int i = 0; i < n; i++) {
        min_cost = min(min_cost, func_dp(i, mask | (1<<i), dp, v, n));
    }
    return min_cost;
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
    return 0;
}
