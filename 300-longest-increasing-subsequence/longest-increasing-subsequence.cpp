class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tails;
        for(int num: nums){
            int pos = lower_bound(tails.begin(), tails.end(), num) - tails.begin();

            if(pos == tails.size()){
                tails.push_back(num);
            }else{
                tails[pos] = num;
            }
        }

return tails.size();
    }
};