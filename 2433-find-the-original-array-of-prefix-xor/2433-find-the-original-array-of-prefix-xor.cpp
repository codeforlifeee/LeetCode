class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
          
        ans.push_back(pref[0]);
        for (int i = 1; i < pref.size(); i++) {
            int val = pref[i] ^ pref[i - 1]; 
            ans.push_back(val); 
        }
        return ans;
    }
};