class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // Start with the smallest lexicographic permutation
        res.push_back(nums);             // Store the first permutation

        while (next_permutation(nums.begin(), nums.end())) {
            res.push_back(nums);
        }

        return res;
    }
};
