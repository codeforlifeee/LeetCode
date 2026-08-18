class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        
        unordered_map<int, int> freq;
        
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_nums(nums.begin() + i, nums.begin() + i + k);
            for (int num : unique_nums) {
                freq[num]++;
            }
        }

        int result = -1;
        for (const auto& [num, count] : freq) {
            if (count == 1) {
                result = max(result, num);
            }
        }
        
        return result;
    }
};
