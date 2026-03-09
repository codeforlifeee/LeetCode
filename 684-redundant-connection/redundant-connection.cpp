class UnionFind {
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        components = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } 
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        } 
        else {
            parent[py] = px;
            rank[px]++;
        }

        components--;
    }

    int getComponents() {
        return components;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        UnionFind uf(n + 1);   // nodes are 1-indexed

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (uf.find(u) == uf.find(v)) {
                return edge;   // redundant edge found
            }

            uf.unite(u, v);
        }

        return {};
    }
};