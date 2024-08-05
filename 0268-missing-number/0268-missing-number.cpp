class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Tsum = (n*(n+1))/2;
        int sum=0;
        for(int i = 0; i<n; i++){
            sum = sum + nums[i];
        }
        int missingNum = Tsum-sum;
        return missingNum;
    }
};