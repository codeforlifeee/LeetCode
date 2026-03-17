class Solution {
public:
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // base cases
        if (amount == 0) return 0;
        if (idx == coins.size()) return 1e9; // impossible

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int take = 1e9;
        if (coins[idx] <= amount) {
            // take: stay on same index (unbounded use)
            take = 1 + solve(idx, amount - coins[idx], coins, dp);
        }

        // skip: move to next index
        int skip = solve(idx + 1, amount, coins, dp);

        return dp[idx][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};