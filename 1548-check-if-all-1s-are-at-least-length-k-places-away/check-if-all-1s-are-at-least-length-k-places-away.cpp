class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zeroCount = k;  // initialize to k so first 1 is always valid
        
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else { // num == 1
                if (zeroCount < k) {
                    return false;
                }
                zeroCount = 0;
            }
        }
        return true;
    }
};
