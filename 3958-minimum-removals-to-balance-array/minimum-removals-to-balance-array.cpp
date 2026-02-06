class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
         int n = nums.size();
        if (n <= 1) 
            return 0;  // Already balanced
        
        sort(nums.begin(), nums.end());
        
        int maxKeep = 1;  // At least one element can always stay
        int r = 0;
        
        for (int l = 0; l < n; ++l) {
            // Expand r while window [l…r] stays balanced
            while (r < n && (long long)nums[r] <= (long long)nums[l] * k) {
                ++r;
            }
            // Window [l…r-1] is valid
            maxKeep = max(maxKeep, r - l);
        }
        
        // Remove all other elements
        return n - maxKeep;

    }
};