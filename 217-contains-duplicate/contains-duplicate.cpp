class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>freq;

        for(int it : nums){
            if(freq.count(it)){
                return true;
            }
            freq.insert(it);
        }        
        
        return false;
    }
};