class Solution {
public:
    //int t[2001][2001];
    
    int solve(vector<int>&nums, int i , int currsum, int target, unordered_map<string, int>&mp){
        
        if(i == nums.size()){
            if(currsum == target) return 1;
            else return 0;
        }
        
//         if(t[i][currsum + 1000] != -1){
//             return t[i][currsum + 1000];
//         }
        
        string key = to_string(i) + "_" + to_string(currsum);
        
        if(mp.count(key)){
            return mp[key];
        }
        
        int take = solve(nums, i+1, currsum + nums[i], target, mp);
        
        int nottake = solve(nums, i+1, currsum-nums[i] , target, mp);
        
        
        return mp[key] =  take + nottake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<string, int>mp;
        
        
       // memset(t,-1,sizeof(t));
        
        return solve(nums, 0,0,target, mp);
        
        
    }
};