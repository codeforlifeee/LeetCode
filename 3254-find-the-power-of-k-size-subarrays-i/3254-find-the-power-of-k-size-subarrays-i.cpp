class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i =0; i<=n-k; i++){
            bool istrue = true;
            int maxi = nums[i];
            for(int  j = i+1;j<i+k; j++){
                if(nums[j]!= nums[j-1]+1){
                    istrue = false;
                    break;
                }
                maxi = max(maxi, nums[j]);
            }
            if(istrue){
                res.push_back(maxi);
            }
            else{
                res.push_back(-1);
            }

        }
        return res;
    }
};