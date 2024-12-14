class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        int i = 0;
        long long ans = 0;
        while (k > 0 && i < n) {
            int maxIndex = distance(gifts.begin(), max_element(gifts.begin(), gifts.end()));
            //distance returns the index of the element
            gifts[maxIndex] = floor(sqrt(gifts[maxIndex]));
            k--;
        }
        for(int i = 0;i < n;i++){
            ans += gifts[i];
        }
        return ans;
    }
};
