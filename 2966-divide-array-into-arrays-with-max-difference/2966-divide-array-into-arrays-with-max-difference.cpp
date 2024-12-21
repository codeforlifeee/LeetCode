class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n  = nums.size();
        
        vector<vector<int>>answer;
        
        sort(nums.begin(),nums.end());
        
        for (int i = 0; i < n; i += 3) {
            // Check if there are at least 3 elements left to form a triplet
            if (i + 2 < n) {
                // Check if the difference between the largest and smallest element is greater than k
                if (nums[i+2] - nums[i] > k) {
                    return {};  // Return an empty result if the condition is met
                }
                // Push the current triplet into the answer vector
                answer.push_back({nums[i], nums[i+1], nums[i+2]});
            }
        }
        return answer;
    }
};