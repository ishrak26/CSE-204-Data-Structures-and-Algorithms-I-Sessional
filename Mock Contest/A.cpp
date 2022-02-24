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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    int idx = 0, cnt = 0;
    for (int i = 0; i < n && idx < m; i++) {
        ll tar = a[i]-k;
        while (idx < m && b[idx] < tar) {
            idx++;
        }
        if (idx == m) break;
        if (b[idx] <= a[i]+k) {
            cnt++;
            idx++;
        }
    }
    cout << cnt << '\n';
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
