class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        vector<int>positions;
        for(int i= 0; i<nums.size(); i++){
            if(nums[i] != target[i]){
                positions.push_back(i);
            }
        }
        set<int>uniq;
        for(int it : positions){
            uniq.insert(nums[it]);
        }
        return uniq.size();

    }
};