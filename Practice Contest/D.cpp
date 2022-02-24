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

void solve(int n, int m) {
    vector<vi> G(n);
    vp e(m);
    vi cost(m);
    int curr = 0;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        curr += c;
        G[u].PB(i);
        G[v].PB(i);
        e[i] = {u, v};
        cost[i] = c;
    }
    priority_queue<pii, vp, greater<pii>> pq;
    vector<bool> mark(n, 0);
    mark[0] = 1;
    for (int edge : G[0]) {
        pq.push({cost[edge], edge});
    }
    int cnt = 1;
    int mst = 0;
    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        int u = e[p.second].first;
        int v = e[p.second].second;
        if (mark[u] && mark[v]) continue;
        cnt++;
        mst += p.first;
        if (cnt == n) break;
        if (!mark[v]) {
            u = v;
        }
        mark[u] = 1;
        for (int edge : G[u]) {
            if (edge == p.second) continue;
            pq.push({cost[edge], edge});
        }
    }
    cout << curr - mst << '\n';
}

int main() {
    FASTIO;
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
    return 0;
}
