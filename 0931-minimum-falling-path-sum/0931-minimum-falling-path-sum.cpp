class Solution {
public:
    int t[300][300];
    
    int solve(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (j < 0 || j >= m) {
            return INT_MAX;
        }

        if (i == n - 1) {
            return matrix[i][j];
        }

        if (t[i][j] != INT_MAX) {
            return t[i][j];
        }

        int leftDiagonal = solve(matrix, i + 1, j - 1);
        int down = solve(matrix, i + 1, j);
        int rightDiagonal = solve(matrix, i + 1, j + 1);

        // Store and return the result
        return t[i][j] = matrix[i][j] + min({leftDiagonal, down, rightDiagonal});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j] = INT_MAX;
            }
        }
        
        int result = INT_MAX;

        for (int j = 0; j < m; j++) {
            result = min(result, solve(matrix, 0, j));
        }

        return result;
    }
};
