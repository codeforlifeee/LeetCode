class Solution {
public:
    int jump(vector<int>& nums) {
            int n = nums.size();
    int jumps = 0, currentEnd = 0, farthest = 0;

    // We do not need to check the last element
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);

        // When we reach the end of the current jump
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;

    }
};