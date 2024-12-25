class Solution {
public:
    int t[1000001];
    
    int solve(vector<int>&nums, int i){
       int n = nums.size();
        
       if(i >= n-1) return 1;
        
        if(t[i] != -1) return t[i];
        
       for(int j = 1; j <= nums[i]; j++){
            if(solve(nums, i + j)){
                return t[i] = 1;
            }
        }
        return t[i] = 0;
    }
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);  
    }
};
