class Solution {
public:
    int solve(int i, vector<int>& arr, vector<int>& dp) {
    if(i < 0) return 0; 
    if(i == 0) return arr[0]; // base case, only one element
    if(dp[i] != -1) return dp[i];

    int include = arr[i] + solve(i - 2, arr, dp);

    int exclude = solve(i - 1, arr, dp);

    return dp[i] = max(include, exclude);
}

    int rob(vector<int>& arr) {
        int n = arr.size();
            vector<int> dp(n, -1);
    return solve(n - 1, arr, dp);

    }
};