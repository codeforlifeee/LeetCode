class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int,int)> dfs=[&](int idx,int t){
            if (t==0) { ans.push_back(cur); return; }
            if (t<0 || idx>=candidates.size()) return;
            cur.push_back(candidates[idx]);
            dfs(idx, t-candidates[idx]);
            cur.pop_back();
            dfs(idx+1, t);
        };
        dfs(0,target);
        return ans;
    }
};
