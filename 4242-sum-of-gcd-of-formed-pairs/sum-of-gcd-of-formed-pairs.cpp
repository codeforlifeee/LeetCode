class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n);

        for(int i=0; i<n; i++){
            if(i == 0) maxi[i] = nums[i];
            else maxi[i] = max(maxi[i-1],nums[i]);
        }

        vector<int>prefixgcd(n);
        for(int i = 0; i<n; i++){
            prefixgcd[i] = __gcd(nums[i], maxi[i]);
        }

        sort(prefixgcd.begin(), prefixgcd.end());
        
        long long ans = 0;
        
        for(int i = 0; i < n/2; i++) {
            ans += __gcd(prefixgcd[i], prefixgcd[n-1-i]);
        }

        return ans;


    }
};