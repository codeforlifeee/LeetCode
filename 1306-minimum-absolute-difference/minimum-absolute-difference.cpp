class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // O(n log n)
        int minimumAbsDiff = INT_MAX;
        vector<vector<int>> ans;

        // Find minimum absolute difference by checking adjacent pairs
        for (int i = 1; i < arr.size(); i++) {
            minimumAbsDiff = min(minimumAbsDiff, arr[i] - arr[i - 1]);
        }

        // Collect all pairs with minimum difference
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minimumAbsDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
