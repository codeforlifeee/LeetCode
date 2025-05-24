class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxjump = nums[0];

        for(int i = 1; i<n; i++){
            if(i <= maxjump){
                maxjump = max(maxjump, i + nums[i]);
            }
        }
        
        if(maxjump >= n-1) 
            return true;
        
        return false;

        
    }
};