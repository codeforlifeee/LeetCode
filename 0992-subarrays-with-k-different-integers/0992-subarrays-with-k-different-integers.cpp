class Solution {
public:
    
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // To store the frequency of elements
        int n = nums.size();
        int i = 0, j = 0;            // Two pointers for the sliding window
        int count = 0;

        while (j < n) {
            mp[nums[j]]++;  // Include current element in the window

            // If window size (distinct elements) exceeds k, shrink from the left
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);  // Remove element from map if its frequency becomes 0
                }
                i++;  // Shrink the window
            }

            // Add the number of valid subarrays ending at index j
            count += (j - i + 1);
            j++;  // Expand the window from the right
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
        
    }
};