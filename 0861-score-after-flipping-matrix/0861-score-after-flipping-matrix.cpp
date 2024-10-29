class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();    
        int n = grid[0].size(); 
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) { 
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }

        int totalScore = 0;
        for (int j = 0; j < n; ++j) {
            int countOnes = 0;
            for (int i = 0; i < m; ++i) {
                countOnes += grid[i][j]; 
            }

            int maxOnes = max(countOnes, m - countOnes);
            totalScore += maxOnes * (1 << (n - j - 1)); 
        }

        return totalScore;
    }
};
