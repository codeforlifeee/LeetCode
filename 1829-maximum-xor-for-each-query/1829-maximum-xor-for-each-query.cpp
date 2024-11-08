class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>result(n);
        
        int xorr = 0;
        
        for(int i = 0;i<n; i++){
            xorr ^= nums[i];
        }
        int mask = ((1<<maximumBit)-1);
        
        for(int i = 0; i<n; i++){
            int k = xorr^mask;
            result[i] = k;
            
            xorr = (xorr^nums[n-1-i]);
        }
        
        return result;
    }
};