class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while(k--){
            int element = pq.top();
            ans += element;
            pq.pop();
            pq.push(ceil(element/3.0));
        }
        
        return ans;
    }
};