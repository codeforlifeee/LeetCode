class Solution {
    /*
    1 indexed integer array nums of length n
    nums[i] of nums is called special if i divides n
    
    n%i == 0
    
    */
public:
    int sumOfSquares(vector<int>& nums) {
        
        int n = nums.size();
        int answer = 0;
        
        for(int i = 1; i <= n; i++) {
            if (n % i == 0) {
                int ind = i - 1;
                answer += nums[ind] * nums[ind];
            }
        }
        
        return answer;
    }
};