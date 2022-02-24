#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 200005

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

ll c[SZ], m[SZ];

void solve(int t) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        c[i] = a+c[i-1];
    }
    m[0] = 0;
    for (int i = 1; i <= n; i++) {
        m[i] = min(m[i-1], c[i]);
    }
    ll ma = c[1];
    for (int i = 2; i <= n; i++) {
        ma = max(ma, c[i]-m[i-1]);
    }
    cout << ma << '\n';
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
