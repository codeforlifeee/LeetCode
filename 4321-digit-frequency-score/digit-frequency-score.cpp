class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);

        while(n > 0){
            int digit = n%10;
            freq[digit]++;
            n = n/10;
        }
        int ans = 0;
        for(int d = 0; d<=9; d++){
            ans += d * freq[d];
        }
        return ans;
    }
};