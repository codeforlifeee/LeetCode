class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         unordered_map<int, int> countMap;
    
        for (int num : nums) {
            countMap[num]++;
        }
        
        vector<int> result;
    
        for (const auto& entry : countMap) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
        
    }
};