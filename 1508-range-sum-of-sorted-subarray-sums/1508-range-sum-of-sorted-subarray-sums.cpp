class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
    const int MOD = 1e9 + 7;
    vector<int>subarraysum;

    for (int i = 0; i < n; i++){
        int currentSum = 0;

        for (int j = i; j < n; j++){
            currentSum += nums[j];  
            subarraysum.push_back(currentSum);
        }
    }
        
        sort(subarraysum.begin(),subarraysum.end());
        int ans =0;
        for(int i = left-1; i<right; i++){
            ans = (ans+ subarraysum[i] )% MOD;
        }
        return ans;
    }
};