class Solution {
public:
    int t[2001][2001];
    
    int solve(vector<int>&nums, int i , int currsum, int target){
        
        if(i == nums.size()){
            if(currsum == target) return 1;
            else return 0;
        }
        
        if(t[i][currsum + 1000] != -1){
            return t[i][currsum + 1000];
        }
        
        int take = solve(nums, i+1, currsum + nums[i], target);
        
        int nottake = solve(nums, i+1, currsum-nums[i] , target);
        
        
        return t[i][currsum + 1000] = take + nottake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        memset(t,-1,sizeof(t));
        
        return solve(nums, 0,0,target);
        
        
    }
};