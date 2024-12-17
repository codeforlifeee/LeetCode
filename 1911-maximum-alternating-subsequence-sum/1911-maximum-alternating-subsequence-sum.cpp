class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<ll>> t(n+1, vector<ll>(2,0));
        //even: 0, odd : 1
        
        for(int i = 1; i< n+1; i++){
            //even length
            t[i][0] = max(t[i-1][1]-nums[i-1], t[i-1][0]);
            
            //odd length
            t[i][1] = max(t[i-1][0]+nums[i-1], t[i-1][1]);
        }
        return max(t[n][0], t[n][1]);
        
    }
};