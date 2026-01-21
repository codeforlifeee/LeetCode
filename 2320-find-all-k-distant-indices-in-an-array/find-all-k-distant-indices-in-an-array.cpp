class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                for (int i = max(0, j - k); i <= min(n - 1, j + k); i++) {
                    st.insert(i);
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
