#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

// computes the length of the longest common subsequence
// string a vertically in dp table, string b horizontally
int LCS(vector<vector<int>>& dp, int m, int n, const string &a, const string &b) {
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// finds the first LCS present in string a
string backtrack(const vector<vector<int>>& dp, int i, int j, const string &a, const string &b) {
    if (i == 0 || j == 0)
        return "\0";
    if (a[i] == b[j])
        return backtrack(dp, i-1, j-1, a, b) + a[i];
    if (dp[i-1][j] == dp[i][j])
        return backtrack(dp, i-1, j, a, b);
    assert(dp[i][j-1] == dp[i][j]);
    return backtrack(dp, i, j-1, a, b);
}

int main() {
    string a, b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();

    a = '0' + a; // make the string 1-indexed for ease of computation
    b = '0' + b;

    vector<vector<int>> dp(m+1, vector<int> (n+1));

    int lcs_len = LCS(dp, m, n, a, b);
    string str = backtrack(dp, m, n, a, b);

    cout << lcs_len << '\n' << str << '\n';

    return 0;
}
