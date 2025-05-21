class Solution {
public:
    bool canRob(const vector<int>& nums, int k, int capability) {
        int count = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] <= capability) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canRob(nums, k, mid)) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
