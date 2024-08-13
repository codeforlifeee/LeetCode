class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementCount;

        
        for (int num : nums) {
            ++elementCount[num];
        }

        
        for (const auto& pair : elementCount) {
            if (pair.second > nums.size() / 2) {
                return pair.first; 
            }
        }
        return -1; 
    }
        
    
};