#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 2005

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vp;
typedef vector<pll> vpll;

// const ld PI = acos(-1.0);
// const ll MOD = 1000000007;

int dp[SZ][SZ];

int func(const string &a, const string &b, int m, int n) {
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) dp[i][0] = i;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    return dp[m][n];
}

void solve(int t) {
    string a, b;
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;
    int m = a.length();
    int n = b.length();
    cout << func(a, b, m, n) << '\n';
}

int main() {
    FASTIO;
    int tc;
//    tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}
