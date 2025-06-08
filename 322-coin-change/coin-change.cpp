class Solution {
public:
    int t[100001];

    int solve(vector<int>& coins, int amount) {
        if (amount < 0) return INT_MAX;  // Invalid case
        if (amount == 0) return 0;       // No coins needed to make 0

        if (t[amount] != -1) return t[amount];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = solve(coins, amount - coin);
            if (res != INT_MAX) {
                minCoins = min(minCoins, res + 1);
            }
        }

        return t[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int result = solve(coins, amount);
        return result == INT_MAX ? -1 : result;
    }
};
