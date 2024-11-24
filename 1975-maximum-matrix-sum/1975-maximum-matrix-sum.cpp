class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
           int m = matrix.size();
           int n = matrix[0].size();
        int negc = 0;
        int mini = INT_MAX;
  long long Tsum = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]< 0){
                    negc++;
                }
                Tsum = Tsum + abs(matrix[i][j]);
                mini = min(abs(matrix[i][j]),mini);
            }
        }
         if(negc%2 != 0){
            Tsum =  Tsum - 2*mini;
        }
        return Tsum;
    }
};