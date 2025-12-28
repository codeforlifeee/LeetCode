class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        return (s % 2 == 0) ? (n - 1) : 0;
    }
};
