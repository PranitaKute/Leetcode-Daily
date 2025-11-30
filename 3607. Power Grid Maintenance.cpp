#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto& conn : connections)
            dsu.unite(conn[0], conn[1]);

        unordered_map<int, set<int>> gridOnline;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i);
            gridOnline[root].insert(i);
        }

        vector<int> result;
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (gridOnline[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*gridOnline[root].begin());
                    }
                }
            } else {
                if (online[x]) {
                    online[x] = false;
                    gridOnline[root].erase(x);
                }
            }
        }
        return result;
    }
};
