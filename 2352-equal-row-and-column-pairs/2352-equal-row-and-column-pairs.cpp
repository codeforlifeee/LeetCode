class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        //transpose
        vector<vector<int>> transposed(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = grid[i][j];
            }
        }
        //comparing
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i] == transposed[j]) {
                    ++count;  // Found a matching pair
                }
            }
        }

        return count;
    }
};
