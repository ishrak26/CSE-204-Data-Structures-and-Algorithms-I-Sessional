#include<iostream>
#include<assert.h>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

class SnakeLadder {
    int board_size;
    int die_faces;
    // 1-indexed vectors
    vector<int> board; // keeps track of snakes and ladders
    vector<int> level; // keeps track of least no. of rolls for a position
    vector<int> parent; // keeps track of previous rolls
    bool isPlayed;

    void init(int n = 2, int x = 2) {
        die_faces = n;
        board_size = x;
        board.resize(board_size+1, -1);
        isPlayed = false;
    }

    void bfs() {
        level.resize(board_size+1, -1);
        parent.resize(board_size+1, -1);
        queue<int> q;
        level[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (board[u] != -1) {
                // u is the base of a snake/ladder
                // can only move to endpoint of snake/ladder
                int v = board[u];
                if (level[v] == -1) {
                    // v is unvisited
                    level[v] = level[u]; // no extra roll required
                    parent[v] = u;
                    q.push(v);
                }
            }
            else {
                for (int i = 1; i <= die_faces; i++) {
                    int v = u+i;
                    if (v <= board_size && level[v] == -1) {
                        // v is unvisited
                        level[v] = level[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
        }
        isPlayed = true;
    }

    void print_path(int node) {
        assert(isPlayed && node >= 0 && node <= board_size);
        if (parent[node] == -1) {
            // node is the root
            cout << node;
            return;
        }
        print_path(parent[node]);
        cout << "  ->  " << node;
    }

public:
    SnakeLadder() {
        init();
    }

    SnakeLadder(int n, int x, vector<pair<int, int>>& ladders, vector<pair<int, int>>& snakes) {
        die_faces = n;
        board_size = x;
        init(n, x);
        for (int i = 0, sz = ladders.size(); i < sz; i++) {
            board[ladders[i].first] = ladders[i].second;
        }
        for (int i = 0, sz = snakes.size(); i < sz; i++) {
            board[snakes[i].first] = snakes[i].second;
        }
    }

    int find_least_rolls() {
        bfs();
        return level[board_size];
    }

    void trace_path() {
        print_path(board_size);
    }

    vector<int> find_unreachable() {
        assert(isPlayed);
        vector<int> unreachables;
        for (int i = 1; i <= board_size; i++) {
            if (level[i] == -1) unreachables.push_back(i);
        }
        return unreachables;
    }
};
