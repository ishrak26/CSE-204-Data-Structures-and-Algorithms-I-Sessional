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

void solve(int t) {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    while (k--) {
        v[n-1] *= x;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) ans |= v[i];
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
