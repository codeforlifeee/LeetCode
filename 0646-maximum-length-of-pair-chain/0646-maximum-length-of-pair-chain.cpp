class Solution {
    //LIS Code is used Here//with sorting//
public:
    int findLongestChain(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j][1] < nums[i][0]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }
};
