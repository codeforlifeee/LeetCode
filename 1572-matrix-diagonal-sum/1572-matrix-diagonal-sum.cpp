class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
          int n = mat.size();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            
                if (i == j) {
                    answer += mat[i][j];
                }
            
                if (i + j == n - 1 && i != j) {
                    answer += mat[i][j];
                }
            }
        }

        return answer;
        
    }
};