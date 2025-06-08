class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int it : nums) {
            freq[it]++;
        }
        
        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        return -1; // Should never reach here if input meets constraints
    }
};
