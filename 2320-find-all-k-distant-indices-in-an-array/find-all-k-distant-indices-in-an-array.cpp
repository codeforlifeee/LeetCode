class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> find;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==key){
                find.push_back(i);
            }
        }
        unordered_set<int>st;
        for(auto it:find){
            for(int i=0;i<n;i++){
                if(abs(i-it) <=k ){
                    st.insert(i);
                }
            }
        }
        vector<int>result (st.begin(),st.end());
        sort(result.begin(),result.end());
        return result;
    }
};

