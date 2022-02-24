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

int arr[SZ], n;

ll count_inv(int l, int r) {
    ll inv = 0;
    if (l == r) return inv;
    int mid = (l+r)/2;
    inv += count_inv(l, mid);
    inv += count_inv(mid+1, r);
    int sz1 = mid-l+1, sz2 = r-mid;
    vi a(sz1), b(sz2);
    for (int i = 0; i < sz1; i++) a[i] = arr[l+i];
    for (int i = 0; i < sz2; i++) b[i] = arr[mid+1+i];

    for (int i = 0, j = 0, k = l; k <= r; k++) {
        if (i == sz1) {
            while (j < sz2) arr[k++] = b[j++];
            assert(k > r);
            break;
        }
        if (j == sz2) {
            while (i < sz1) arr[k++] = a[i++];
            assert(k > r);
            break;
        }
        if (b[j] < a[i]) {
            inv += sz1-i;
            arr[k] = b[j++];
        }
        else arr[k] = a[i++];
    }
    return inv;
}

void solve(int t) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << count_inv(1, n) << '\n';
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
