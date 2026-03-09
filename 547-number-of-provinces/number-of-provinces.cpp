class Solution {
public:
    void dfs_circle(int person, vector<vector<int>>& isConnected, vector<bool>& visited) {
    visited[person] = true;
    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[person][i] == 1 && !visited[i]) {
            dfs_circle(i, isConnected, visited);
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
    vector<bool> visited(n, false);
    int circles = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_circle(i, isConnected, visited);
            circles++;
        }
    }
    
    return circles;

    }
};