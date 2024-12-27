class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<int>pq;//maxheap
        int ans = 0;
        
        for(int i = 0; i<values.size(); i++){
            if(!pq.empty()){
                ans = max(ans, pq.top() + values[i]-i);
            }
            pq.push(values[i] + i);
        }
        return ans;
    }
};