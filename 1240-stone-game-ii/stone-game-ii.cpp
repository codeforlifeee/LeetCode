class Solution {
public:

    int helper(int i, int m, const vector<int>& suffixSum, vector<vector<int>>& memo, int n){
        if(i >= n) return 0;
        if(i + 2*m  >= n) return suffixSum[i];
        if(memo[i][m] != 0) return memo[i][m];

        int maxStones = 0;

        for(int x = 1; x <= 2*m; x++){
            maxStones = max(maxStones, suffixSum[i] - helper(i+x, max(m,x), suffixSum, memo, n));
        }


        return memo[i][m] = maxStones;
    }
    int stoneGameII(vector<int>& piles) {
        int n  = piles.size();

        vector<int>suffixSum(n+1, 0);

        for(int i =n-1; i>= 0; i--){
            suffixSum[i] = suffixSum[i+1] + piles[i];


        }

        vector<vector<int>> memo(n, vector<int>(n+1, 0));

        return helper(0, 1, suffixSum, memo, n);
        
    }
};