class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
                for (int x : nums) {
            if (x >= 0) {
                nonNeg.push_back(x);
            }
        }
        int m = nonNeg.size();
        if (m <= 1) return nums;
        k = k % m;
        vector<int> rotated(m);
        for (int i = 0; i < m; i++) {
            rotated[i] = nonNeg[(i + k) % m];
        }
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = rotated[idx++];
            }
        }

        return nums;
    }
};
