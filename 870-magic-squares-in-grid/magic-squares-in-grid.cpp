class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Center must be 5
        if (grid[r+1][c+1] != 5) return false;

        int mask = 0;

        // Check numbers 1 to 9 and uniqueness
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if (num < 1 || num > 9) return false;
                if (mask & (1 << num)) return false;
                mask |= (1 << num);
            }
        }

        int SUM = 15;

        // Rows
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM)
                return false;
        }

        // Columns
        for (int j = 0; j < 3; j++) {
            if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != SUM)
                return false;
        }

        // Diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM)
            return false;

        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
