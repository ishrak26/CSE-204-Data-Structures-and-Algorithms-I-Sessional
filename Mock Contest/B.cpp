#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 10005

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vp;
typedef vector<pll> vpll;

// const ld PI = acos(-1.0);
const ll MOD = 10000007;

ll dp[SZ];
int n;

void solve(int t) {
    for (int i = 0; i < 6; i++) {
        cin >> dp[i];
        dp[i] %= MOD;
    }
    cin >> n;
    for (int i = 6; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j = 2; j <= 6; j++) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << "Case " << t << ": " << dp[n] << '\n';
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
