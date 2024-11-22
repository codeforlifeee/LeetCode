class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_map<string,int>mp;
        
        for(auto &row : matrix){
            string rowkanature = "";
            
            int firstval = row[0];
            
            for(int col = 0; col<n; col++){
                rowkanature += (row[col] == firstval) ? "5": "8";
            }
            mp[rowkanature]++;
        }
        
        int maxrows = 0;
        for(auto &it: mp){
            maxrows = max(maxrows, it.second);
        }
        return maxrows;
    }
};