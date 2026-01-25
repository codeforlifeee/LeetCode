class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size();

    if (k > n) return -1;

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = k - 1;

    int ans = INT_MAX;

    while (right < n) {

        int diff = nums[right] - nums[left];

        ans = min(ans, diff);

        left++;
        right++;
    }

    return ans;


    }
};
