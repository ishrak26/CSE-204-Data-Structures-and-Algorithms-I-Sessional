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

int dp[SZ];

void solve(int t) {
    string s;
    cin >> s;
    int n = s.length();
    s = '0' + s;
    for (int i = 2; i <= n; i++) {
        dp[i] = s[i]==s[i-1] ? dp[i-1]+1 : dp[i-1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l] << '\n';
    }
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
