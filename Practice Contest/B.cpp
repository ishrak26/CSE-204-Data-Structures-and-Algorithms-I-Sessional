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

vi pos;
vector<vp> v;
int sz, cnt;

void solve(int lo, int hi, int idx) {
    assert(lo < hi);
    if (hi-lo+1 == 2) {
        v[idx][pos[idx]++] = {lo, lo};
        cnt = max(cnt, idx);
        return;
    }
    if (hi-lo+1 == 3) {
        v[idx][pos[idx]++] = {lo, lo};
        v[idx+1][pos[idx+1]++] = {lo, lo+1};
        cnt = max(cnt, idx+1);
        return;
    }
    int mid = (lo+hi)/2;
    v[idx][pos[idx]++] = {lo, mid};
    cnt = max(cnt, idx);
    solve(lo, mid, idx+1);
    solve(mid+1, hi, idx+1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    sz = (n+1)/2;
    v.resize(sz, vp(sz, {-1, -1}));
    pos.resize(sz, 0);
    solve(1, n, 0);
    cout << cnt+1 << '\n';
    for (int i = 0; i <= cnt; i++) {
        int k = 0;
        for (int j = 0; j < pos[i]; j++) {
            k += v[i][j].second-v[i][j].first+1;
        }
        cout << k << ' ';
        for (int j = 0; j < pos[i]; j++) {
            for (int k = v[i][j].first; k <= v[i][j].second; k++) cout << k << ' ';
        }
        cout << '\n';
    }
    return 0;
}
