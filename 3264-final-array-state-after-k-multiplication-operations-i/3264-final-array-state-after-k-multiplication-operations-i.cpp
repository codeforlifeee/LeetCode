class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P, vector<P>, greater<P>> minHeap;
        
        for(int i = 0; i < nums.size(); ++i){
            minHeap.push({nums[i], i});
        }
            
        while(k--){
            P top = minHeap.top();
            minHeap.pop();
            
            top.first *= multiplier;
            
            minHeap.push(top);
            
        }
        
        vector<int> ans(nums.size());
        while (!minHeap.empty()) {
            P top = minHeap.top();
            minHeap.pop();
            ans[top.second] = top.first;
        }
        return ans;        
    }
};