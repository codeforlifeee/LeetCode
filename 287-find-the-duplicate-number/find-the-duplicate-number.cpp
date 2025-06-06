class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int it : nums){
            freq[it]++;
        }
        int ans = 0;
        for(auto it : freq){
            if(it.second >= 2){
                ans = it.first;
            }
        }

    return ans;

        
    }
};