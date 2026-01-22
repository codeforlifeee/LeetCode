class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            int curr = nums[i % n];
            int next = nums[(i + 1) % n];
            maxDiff = max(maxDiff, abs(curr - next));
        }

        return maxDiff;
    }
};

