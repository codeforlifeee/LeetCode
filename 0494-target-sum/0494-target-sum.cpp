class Solution {
public:
    int solve(vector<int>&nums, int i , int currsum, int target){
        
        if(i == nums.size()){
            if(currsum == target) return 1;
            else return 0;
        }
        
        int take = solve(nums, i+1, currsum + nums[i], target);
        
        int nottake = solve(nums, i+1, currsum-nums[i] , target);
        
        
        return take + nottake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return solve(nums, 0,0,target);
        
        
    }
};