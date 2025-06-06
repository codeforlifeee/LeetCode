class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];  // Mark as seen by negating
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);  // i+1 is missing
            }
        }

        return result;
    }
};
