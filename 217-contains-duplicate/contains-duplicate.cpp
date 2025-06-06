class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());

        int ssize = st.size();
        int vsize = nums.size();

        return !(ssize == vsize);
        
    }
};