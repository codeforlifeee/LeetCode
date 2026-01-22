class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int maxDiff = INT_MIN;

        vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());

        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            maxDiff = max(maxDiff, abs(arr[i] - arr[i + 1]));
        }

        return maxDiff;
    }
};
