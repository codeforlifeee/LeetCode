class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sets;//stores all the subsets
        int n= nums.size();
        int subsetCount = 1<<n;//2^n
        
        for(int i = 0; i<subsetCount; i++){
            vector<int>subset;
            for(int j = 0; j<n; j++){
                if(i & (1<<j)){//checking if jth bit of i is set or not
                    subset.push_back(nums[j]);
                }
            }
            sets.push_back(subset);
        }
        return sets;
        
        
    }
};