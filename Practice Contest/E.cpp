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
    int ma = -1;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        if (foo > ma) {
            ma = foo;
            idx = i;
        }
    }
    int m;
    cin >> m;
    vector<vi> G(n);
    vp edge(m);
    vi cost(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        cost[i] = w;
        edge[i] = {u, v};
        G[u].PB(i);
    }

    priority_queue<pii, vp, greater<pii>> pq;
    vector<bool> mark(n, 0);
    mark[idx] = 1;
    for (int x : G[idx]) pq.push({cost[x], x});
    int cnt = 1, mst = 0;
    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        pii e = edge[p.second];
        assert(mark[e.first]);
        if (mark[e.second]) continue;
        mst += p.first;
        mark[e.second] = 1;
        cnt++;
        if (cnt == n) break;
        for (int x : G[e.second]) pq.push({cost[x], x});
    }
    if (cnt < n) mst = -1;
    cout << mst << '\n';
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
