#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 60005

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

int dp[SZ];

int func(int n) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i- j*j] + 1);
        }
    }
    return dp[n];
}

void solve(int t) {
    int n;
    cin >> n;
    cout << func(n) << '\n';
}

int main() {
    FASTIO;
    int tc;
    tc = 1;
//    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}
