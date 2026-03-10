class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            // Build adjacency list
    vector<vector<int>> graph(n + 1);
    for (auto& d : dislikes) {
        graph[d[0]].push_back(d[1]);
        graph[d[1]].push_back(d[0]);
    }
    
    vector<int> color(n + 1, -1);
    
    for (int start = 1; start <= n; start++) {
        if (color[start] != -1) continue;
        
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int person = q.front();
            q.pop();
            
            for (int disliked : graph[person]) {
                if (color[disliked] == -1) {
                    color[disliked] = 1 - color[person];
                    q.push(disliked);
                } else if (color[disliked] == color[person]) {
                    return false;
                }
            }
        }
    }
    
    return true;

    }
};