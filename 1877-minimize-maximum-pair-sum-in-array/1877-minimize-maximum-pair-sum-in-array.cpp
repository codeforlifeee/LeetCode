class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxPairSum = 0;
        
        for (int i = 0; i < n / 2; i++) {
            int pairSum = nums[i] + nums[n - 1 - i];
            maxPairSum = max(maxPairSum, pairSum);
        }
        
        return maxPairSum;
        
    }
};