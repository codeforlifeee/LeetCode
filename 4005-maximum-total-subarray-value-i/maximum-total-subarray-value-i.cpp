class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        long long answer = (long long)(maxi - mini)*k;
        return answer;
    }
};