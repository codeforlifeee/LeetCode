class NumArray {
public:
    vector<int> copy;
    
    NumArray(vector<int>& nums) {
        // Copy nums into copy vector
        for (int it : nums) {
            copy.push_back(it);
        }
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            ans += copy[i];
        }
        return ans;
    }
};
