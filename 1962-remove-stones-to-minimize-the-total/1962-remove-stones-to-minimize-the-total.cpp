class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k > 0) {
         int largestPile = pq.top();
            pq.pop();
            int reducedPile = largestPile - largestPile / 2;
            pq.push(reducedPile); 
            k--;  
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
