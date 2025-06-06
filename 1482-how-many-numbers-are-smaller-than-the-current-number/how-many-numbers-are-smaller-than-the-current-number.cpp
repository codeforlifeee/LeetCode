class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0); // Because 0 <= nums[i] <= 100

        // Count frequencies
        for (int num : nums)
            count[num]++;

        // Compute prefix sum
        for (int i = 1; i < 101; ++i)
            count[i] += count[i - 1];

        // Build result
        vector<int> res;
        for (int num : nums) {
            if (num == 0)
                res.push_back(0);
            else
                res.push_back(count[num - 1]);
        }

        return res;
    }
};
