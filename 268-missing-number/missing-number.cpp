class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Asum = n*(n+1)/2;
        int Tsum = accumulate(nums.begin(), nums.end(), 0);
        return Asum - Tsum;
    }
};