class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Case 1: only one element
        if (nums.size() == 1)
            return nums[0];

        unordered_set<int> st;
        int sum = 0;
        int mx = *max_element(nums.begin(), nums.end());

        // Sum unique positive elements
        for (int x : nums) {
            if (x > 0 && st.find(x) == st.end()) {
                sum += x;
                st.insert(x);
            }
        }

        // Case 2: all elements are non-positive
        if (sum == 0)
            return mx;

        return sum;
    }
};
