class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        // -1 implies not coloured

        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;
            // If node i has already been colored (visited),
            // skip it and move to the next node.

            queue<int> q;
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    if (color[nei] == -1) {
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    } else if (color[nei] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};