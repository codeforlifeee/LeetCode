class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int result = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] <= target) {
                result = mid;  
                l = mid + 1;  
            } else {
                r = mid - 1;  
            }
        }
        
        return result;
    }
    
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int maxBeauty = 0;
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int y = x + 2 * k;
            int j = binarySearch(nums, y); 
            
            maxBeauty = max(maxBeauty, j - i + 1);
        }
        
        return maxBeauty;
    }
};
