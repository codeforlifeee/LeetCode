class Solution {
public:
int dp[1000001][2];
int solve(int day, bool canBuy, vector<int>& prices) {
    if(day == prices.size()) return 0;
    if(dp[day][canBuy] != -1) return dp[day][canBuy];

    int profit = 0;
    // buy today -> dont buy again
    // didnt buy -> then buy

    // sell today -> then buy
    // didnt sell -> dont buy then

    if (canBuy) {
        // Option 1: Buy today
        int buyToday = -prices[day] + solve(day + 1, false, prices);
        // Option 2: Skip today
        int skip = solve(day + 1, true, prices);
        profit = max(buyToday, skip);
    } else {
        // Option 1: Sell today
        int sellToday = prices[day] + solve(day + 1, true, prices);
        // Option 2: Skip today
        int skip = solve(day + 1, false, prices);
        profit = max(sellToday, skip);
    }

    return dp[day][canBuy] = profit;
}


    int maxProfit(vector<int>& prices) {
    memset(dp, -1, sizeof(dp));
    return solve(0, true, prices); // Start from day 0, we are allowed to buy

    }
};