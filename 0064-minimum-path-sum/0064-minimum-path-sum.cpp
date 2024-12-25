class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&t) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) { 
            return INT_MAX; 
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }

        if (i == m - 1 && j == n - 1) { 
            return grid[i][j]; 
        }

        int down = solve(grid, i + 1, j,t);
        int right = solve(grid, i, j + 1,t);

        return t[i][j] = grid[i][j] + min(down, right); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m, vector<int>(n,-1));

        return solve(grid, 0, 0,t); 
    }
};