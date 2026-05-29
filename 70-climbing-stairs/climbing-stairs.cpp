class Solution {
public:
    int dp[10001];

    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int climbStairs(int n) {
        if (n <= 2) return n;

        if (dp[n] != -1) return dp[n];

        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};