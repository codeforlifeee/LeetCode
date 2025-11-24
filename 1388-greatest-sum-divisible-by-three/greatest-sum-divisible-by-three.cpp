class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums;
    int n;

    // solve(index, remainder)
    int solve(int i, int r) {
        if (i == n) {
            // If we ended with remainder 0 → valid
            return (r == 0 ? 0 : INT_MIN/2);
        }

        if (memo[i][r] != INT_MIN)
            return memo[i][r];

        // Option 1: skip current element
        int skip = solve(i + 1, r);

        // Option 2: take current element
        int take = nums[i] + solve(i + 1, (r + nums[i]) % 3);

        return memo[i][r] = max(skip, take);
    }

    int maxSumDivThree(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        memo.assign(n, vector<int>(3, INT_MIN));

        int ans = solve(0, 0);

        // If impossible (shouldn't happen), return 0
        return ans < 0 ? 0 : ans;
    }
};
