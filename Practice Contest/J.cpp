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

int set_bit(ll n) {
    for (int i = 35; i >= 0; i--) {
        if (n & (1LL<<i)) return i;
    }
    return -1;
}

void solve(int t) {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll pro = 1;
    while (k--) pro *= x;
    x = pro;

    vll first(n, 0), last(n, 0);
    first[0] = v[0];
    for (int i = 1; i < n; i++) first[i] = first[i-1] | v[i];

    last[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) last[i] = last[i+1] | v[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll val = 0;
        if (i > 0) val |= first[i-1];
        val |= v[i]*x;
        if (i+1 < n) val |= last[i+1];
        ans = max(ans, val);
    }
    cout << ans << '\n';
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
