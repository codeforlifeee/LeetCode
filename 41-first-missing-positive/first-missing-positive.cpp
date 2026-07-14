class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     if(nums.empty()) return 1;
     int n = nums.size();

     for(int i = 0; i<n; i++){
        while(1 <= nums[i] && nums[i] <= n && nums[nums[i]-1] != nums[i]){
            swap(nums[nums[i]-1], nums[i]);
        }
     }   

     for(int i = 0; i<n; i++){
        if(nums[i] != i +1) return i +1;
     }
     return n +1;
    }
};