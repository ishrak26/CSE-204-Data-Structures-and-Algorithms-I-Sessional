#include <bits/stdc++.h>

using namespace std;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define PB push_back

#define SZ 105

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

int c[SZ], n;

int calc_one(int l, int r) {
    if (l > r) return 0;
    return c[r] - c[l-1];
}

int calc_zero(int l, int r) {
    if (l > r) return 0;
    return (r-l+1) - calc_one(l, r);
}

void solve(int t) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        c[i] = c[i-1];
        if (a == 1) c[i]++;
    }
    int ma = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ma = max(ma, calc_one(1, i-1) + calc_zero(i, j) + calc_one(j+1, n));
        }
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
