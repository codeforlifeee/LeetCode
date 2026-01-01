class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void BFS(vector<vector<int>>& heights, queue<pair<int,int>>& q,
             vector<vector<bool>>& visited) {

        int m = heights.size();
        int n = heights[0].size();

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto &dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                // boundary + visited check
                if(ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])
                    continue;

                // must flow from higher or equal height
                if(heights[ni][nj] < heights[i][j])
                    continue;

                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pacificQ, atlanticQ;

        // Pacific: top row + left column
        for(int j = 0; j < n; j++) {
            pacificQ.push({0, j});
            pacific[0][j] = true;
        }
        for(int i = 0; i < m; i++) {
            pacificQ.push({i, 0});
            pacific[i][0] = true;
        }

        // Atlantic: bottom row + right column
        for(int j = 0; j < n; j++) {
            atlanticQ.push({m-1, j});
            atlantic[m-1][j] = true;
        }
        for(int i = 0; i < m; i++) {
            atlanticQ.push({i, n-1});
            atlantic[i][n-1] = true;
        }

        // BFS from both oceans
        BFS(heights, pacificQ, pacific);
        BFS(heights, atlanticQ, atlantic);

        // Result
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
