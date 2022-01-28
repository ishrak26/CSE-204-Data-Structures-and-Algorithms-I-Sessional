#include<iostream>
#include<vector>
#include<utility>
#include "SnakeLadder.h"

using namespace std;

int main() {
    // I/O redirection
    freopen ("in.txt", "r", stdin);
    freopen("out00.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, x, l, s;
        cin >> n >> x;
        cin >> l;
        vector<pair<int, int>> ladders(l);
        for (int i = 0; i < l; i++) cin >> ladders[i].first >> ladders[i].second;
        cin >> s;
        vector<pair<int, int>> snakes(s);
        for (int i = 0; i < s; i++) cin >> snakes[i].first >> snakes[i].second;

        SnakeLadder ob(n, x, ladders, snakes);
        int rolls = ob.find_least_rolls();
        cout << rolls << '\n';
        if (rolls != -1) {
            ob.trace_path();
        }
        else {
            cout << "No Solution";
        }
        cout << '\n';
        vector<int> unr = ob.find_unreachable();
        if (unr.empty()) {
            cout << "All reachable";
        }
        else {
            for (int i = 0, sz = unr.size(); i < sz; i++) cout << unr[i] << ' ';
        }
        cout << "\n\n";
    }
    return 0;
}
