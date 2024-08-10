
class Solution {
public:
    // Helper function to perform DFS and count the number of cells in a region
    int dfs(vector<vector<int>>& grid, int row, int col) {
        // Check if the position is out of bounds or already visited
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid.size() || grid[row][col] != 0) {
            return 0;
        }
        // Mark the current cell as visited
        grid[row][col] = 1;
        // Recursively explore all 4 neighboring cells
        return 1 + dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int regions = 0;

        // Create a larger grid to account for slashes and backslashes
        vector<vector<int>> gridExpanded(n * 3, vector<int>(n * 3, 0));

        // Fill the expanded grid based on slashes and backslashes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    gridExpanded[i * 3 + 0][j * 3 + 2] = 1;
                    gridExpanded[i * 3 + 1][j * 3 + 1] = 1;
                    gridExpanded[i * 3 + 2][j * 3 + 0] = 1;
                } else if (grid[i][j] == '\\') {
                    gridExpanded[i * 3 + 0][j * 3 + 0] = 1;
                    gridExpanded[i * 3 + 1][j * 3 + 1] = 1;
                    gridExpanded[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        // Traverse the expanded grid and count regions
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (gridExpanded[i][j] == 0) { // If it's a part of a region
                    if (dfs(gridExpanded, i, j)) {
                        regions++;
                    }
                }
            }
        }

        return regions;
    }
};
