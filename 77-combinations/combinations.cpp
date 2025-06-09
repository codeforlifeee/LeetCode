class Solution {
public:
    // Time Complexity: O(C(n, k) * k)
    // Explanation: There are C(n, k) combinations, and each takes O(k) time to copy into the result.
    // Space Complexity: O(k) for recursion stack + O(C(n, k) * k) for storing results

    void backtrack(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; ++i) {
            temp.push_back(i);
            backtrack(i + 1, n, k, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(1, n, k, temp, result);
        return result;
    }
};
