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

struct Point {
    int idx;
    ld x;
    ld y;
};

bool comp_x(Point a, Point b) {
    return a.x < b.x;
}

bool comp_y(Point a, Point b) {
    return a.y < b.y;
}

ld calc_distance(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<Point> a;

pii solve(int lo, int hi) {
    int n = hi-lo+1;
    assert(n >= 2);
    if (n == 2) return {lo, hi};
    if (n == 3) {
        ld dis1, dis2, dis3;
        dis1 = calc_distance(a[lo], a[lo+1]);
        dis2 = calc_distance(a[lo+1], a[hi]);
        dis3 = calc_distance(a[lo], a[hi]);
        if (dis1 < dis2 && dis1 < dis3) return {lo, lo+1};
        else if (dis2 < dis3 && dis2 < dis1) return {lo+1, hi};
        return {lo, hi};
    }
    int mid = (lo+hi)/2;
    pii p1 = solve(lo, mid);
    pii p2 = solve(mid+1, hi);
    ld d1 = calc_distance(a[p1.first], a[p1.second]);
    ld d2 = calc_distance(a[p2.first], a[p2.second]);
    pii p;
    ld d;
    if (d1 < d2) {
        d = d1;
        p = p1;
    }
    else {
        d = d2;
        p = p2;
    }

    // strip distance calculation
    int left = hi+1, right = hi+1;
    for (int i = lo; i <= mid; i++) {
        if (a[i].x >= a[mid].x-d) {
            left = i;
            break;
        }
    }
    for (int i = mid+1; i <= hi; i++) {
        if (a[i].x > a[mid].x+d) {
            right = i;
            break;
        }
    }
    vector<Point> v;
    for (int i = left; i < right; i++) v.PB(a[i]);
    sort(v.begin(), v.end(), comp_y);
    pii p3;
    ld d3 = 1e9;
    for (int i = 0, sz = v.size(); i < sz; i++) {
        for (int j = i+1; j <= i+7 && j < sz; j++) {
            ld dis = calc_distance(v[i], v[j]);
            if (dis < d3) {
                d3 = dis;
                p3 = {i, j};
            }
        }
    }
    if (d3 < d) {
        // find indices for vector a to update p
        bool flag1 = 1, flag2 = 1;
        for (int i = left; (flag1 || flag2) && i < right; i++) {
            if (flag1 && v[p3.first].idx == a[i].idx) {
                p.first = i;
                flag1 = 0;
                continue;
            }
            if (flag2 && v[p3.second].idx == a[i].idx) {
                p.second = i;
                flag2 = 0;
            }
        }
        assert(!(flag1 || flag2));
    }
    return p;
}

void solve(int t) {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].idx = i;
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), comp_x);
    pii p = solve(0, n-1);
    ld dis = calc_distance(a[p.first], a[p.second]);
    cout << min(a[p.first].idx, a[p.second].idx) << ' ' << max(a[p.first].idx, a[p.second].idx) << ' ';
    cout << fixed << setprecision(6) << round(dis * 1e6) / 1e6 << '\n';
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
