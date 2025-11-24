class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums;
    int n;

    int dfs(int i, int r) {
        if (i == n) {
            // If remainder is zero, valid sum = 0
            return (r == 0 ? 0 : INT_MIN/2);
        }

        if (memo[i][r] != INT_MIN) 
            return memo[i][r];

        // Option 1: Skip current element
        int skip = dfs(i + 1, r);

        // Option 2: Take current element
        int take = nums[i] + dfs(i + 1, (r + nums[i]) % 3);

        // Best of both
        return memo[i][r] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        memo.assign(n, vector<int>(3, INT_MIN));

        int ans = dfs(0, 0);
        return ans < 0 ? 0 : ans;
    }
};
