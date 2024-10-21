class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n<=1) return 0;
        
        int jumps = 0;
        int currentEnd = 0;
        int maxthatcanreach = 0;
        
        for(int i =0; i<n-1; i++){
            maxthatcanreach = max( maxthatcanreach,i+ nums[i]);
            
            if(i == currentEnd){
                jumps++;
                currentEnd = maxthatcanreach;
                if(currentEnd >= n-1);
            }
        }
        return jumps;
        
        
    }
};