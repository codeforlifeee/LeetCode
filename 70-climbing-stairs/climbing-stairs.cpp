class Solution {
public:
    int climbStairs(int n) {
            if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    // if (n <= 2) return n; //
    int dp[n+1];
    dp[0] = 1; // 1 way to stay at ground
    dp[1] = 1; // 1 way to reach first step
    dp[2] = 2; // 2 ways to reach second step (1+1 or 2)
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

    }
};