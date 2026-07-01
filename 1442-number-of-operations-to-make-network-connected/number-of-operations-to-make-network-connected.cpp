class Solution {
public:
    class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) return false;

        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if(rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }

    int countComponents(int n){
        int count = 0;

        for(int i =0; i<n; i++){
            if(parent[i] == i) count++;
        }
        return count;
    }
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        DSU dsu(n);

        for(auto &edge : connections){
            int u= edge[0]; int v = edge[1];
            dsu.unite(u, v);


        }
                    int components = dsu.countComponents(n);

            return components - 1;

    }
};