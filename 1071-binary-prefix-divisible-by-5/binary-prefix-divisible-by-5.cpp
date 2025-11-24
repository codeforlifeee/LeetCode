class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> result;
    result.reserve(nums.size());
    
    int value = 0;  // will store prefix mod 5
    
    for(int bit : nums) {
        value = (value * 2 + bit) % 5;
        result.push_back(value == 0);
    }
    
    return result;

    }
};