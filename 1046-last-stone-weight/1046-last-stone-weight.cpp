class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int heaviest = pq.top();
            pq.pop();
            int nextheaviest = pq.top();
            pq.pop();

            if (heaviest != nextheaviest) {
                pq.push(abs(heaviest - nextheaviest));
            }
        }
         return pq.empty() ? 0 : pq.top();
    }
};