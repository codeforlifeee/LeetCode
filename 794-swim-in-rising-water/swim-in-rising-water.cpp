class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-heap: {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Start from (0,0)
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int i = curr[1];
            int j = curr[2];

            // Destination reached
            if (i == n - 1 && j == n - 1)
                return time;

            if (visited[i][j])
                continue;

            visited[i][j] = true;

            for (auto &dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni < 0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj])
                    continue;

                int newTime = max(time, grid[ni][nj]);
                pq.push({newTime, ni, nj});
            }
        }

        return -1; // unreachable (won't happen due to problem constraints)
    }
};
