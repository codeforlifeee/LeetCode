class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Sort array first
        int n = arr.size();
        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        int i = 0, j = 1;

        while (j < n) {
            int diff = arr[j] - arr[i];

            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[j]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[j]});
            }

            i++;
            j++;
        }

        return ans;
    }
};
