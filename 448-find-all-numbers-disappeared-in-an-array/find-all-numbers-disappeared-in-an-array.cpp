class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> freq(nums.begin(), nums.end());
        vector<int> result;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq.find(i) == freq.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
