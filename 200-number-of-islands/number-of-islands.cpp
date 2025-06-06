
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
        // Check boundaries and if current cell is land '1'
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') 
            return;
        
        // Mark current cell as visited by setting it to '0'
        grid[r][c] = '0';
        
        // Visit all 4 neighbors (up, down, left, right)
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j, m, n);  // Sink the island
                }
            }
        }
        
        return count;
    }
};
