class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int low = 0, high = n*m-1;
//         while(low<=high){
//             int mid  = (low + high)/2;
//             int row = mid/m, col = mid%m;
//             if(matrix[row][col] == target) return true;
//             else if(matrix[row][col] < target) low = mid + 1;
//             else high = mid -1;
//         }
        
//         return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int flag = 0;
        for(int i = 0; i<m; i++ ){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == target){
                    flag = 1;
                }
            }
        }
        
        return flag;
    }
};