class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;  // map number -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // If complement found in map, return indices
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;

        }
        
        return {};  // No solution found
    }
};
