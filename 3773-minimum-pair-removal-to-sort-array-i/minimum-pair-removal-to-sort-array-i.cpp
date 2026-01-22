class Solution {
public:
    bool isnondecreasing(const vector<int>&nums){
        for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1])
            return false;
    }
    return true;
}

    int minimumPairRemoval(vector<int>& nums) {
      int operations = 0;

        while(!isnondecreasing(nums) && nums.size()>=2){
            int mergeindex = 0;

            int minsum = nums[0] + nums[1];

            for(size_t i = 1;i<nums.size()-1; i++){
                int currentsum = nums[i]  + nums[i+1];

                if(currentsum < minsum){
                    minsum = currentsum;
                    mergeindex = i;
                }
            }

            nums[mergeindex] = nums[mergeindex] + nums[mergeindex + 1];

            nums.erase(nums.begin() + mergeindex + 1);

            operations++;
        }
        return operations;
        
    }
};