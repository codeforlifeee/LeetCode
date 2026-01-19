class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

        // Prefix sum calculation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = pre[i - 1][j] 
                          + pre[i][j - 1] 
                          - pre[i - 1][j - 1] 
                          + mat[i - 1][j - 1];
            }
        }

        // Try square sizes from largest to smallest
        for (int k = min(n, m) - 1; k >= 0; k--) {
            for (int i = 1; i + k <= n; i++) {
                for (int j = 1; j + k <= m; j++) {
                    int sum = pre[i + k][j + k]
                            - pre[i + k][j - 1]
                            - pre[i - 1][j + k]
                            + pre[i - 1][j - 1];

                    if (sum <= threshold)
                        return k + 1;
                }
            }
        }

        return 0;
    }
};
