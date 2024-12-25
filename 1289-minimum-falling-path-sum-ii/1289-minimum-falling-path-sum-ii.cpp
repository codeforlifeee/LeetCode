class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> t(m, vector<int>(m, INT_MAX));
        
        // Initialization
        for (int col = 0; col < m; col++) {
            t[0][col] = A[0][col];
        }
        
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < m; col++) {
                for (int prevCol = 0; prevCol < m; prevCol++) {
                    if (prevCol != col) { // Ensure non-zero shift
                        
                        t[row][col] = min(t[row][col], A[row][col] + t[row - 1][prevCol]);
                        
                    }
                }
            }
        }

        return *min_element(t[m - 1].begin(), t[m - 1].end());
    }
};
