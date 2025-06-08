class Solution {
public:
    int t[46];

    int solve(int n){
        if (n == 0 || n == 1) return 1;  // base cases
        if(t[n] != -1) return t[n];
        int ways = solve(n-1) + solve(n-2);

        return t[n] = ways;
    }

    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
        
    }
};