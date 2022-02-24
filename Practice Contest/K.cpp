#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 100005

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

ll dp[SZ], a[SZ];

void solve(int t) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[2] = abs(a[2]-a[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]), dp[i-2] + abs(a[i]-a[i-2]));
    }
    cout << dp[n] << '\n';
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
