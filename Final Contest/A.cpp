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
    set<int> s;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    set<int>::iterator it;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            cnt++;
            s.insert(v[i]);
        }
        else {
            it = s.find(v[i]-1);
            if (it == s.end()) {
                cnt++;
                s.insert(v[i]);
            }
            else {
                s.insert(v[i]);
            }
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

/*
3
1 3 2
--> 2
*/
