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
    int n;
    cin >> n;
    vp v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    vi rooms(n, -1); // room allocated for the i-th customer
    map<int, vector<vi>> m;
    for (int i = 0; i < n; i++) {
        int a = v[i].first;
        int b = v[i].second;
        if (m[a].empty()) {
            m[a] = vector<vi> (2);
        }
        m[a][0].PB(i);

        if (m[b].empty()) {
            m[b] = vector<vi> (2);
        }
        m[b][1].PB(i);
    }
    map<int, vector<vi>>::iterator it;
    set<int> s;
    for (int i = 1; i <= n+10; i++) s.insert(i);
    for (it = m.begin(); it != m.end(); it++) {
        vector<vi> a = it->second;
        // allocate rooms after arrival
        for (int x: a[0]) {
            rooms[x] = *s.begin();
            s.erase(s.begin());
        }

        // deallocate rooms after departure
        for (int x: a[1]) {
            int room = rooms[x];
            assert(room != -1);
            s.insert(room);
        }
    }
    int ans = -1;
    for (int x:rooms) ans = max(ans, x);
    cout << ans << '\n';
    for (int x:rooms) cout << x << ' ';
    cout << '\n';
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
