class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int remain = 0;
        for(int i = 1; i<=K; i++) {
            remain = (remain*10 + 1)%K; //remainder will never exceed k-1, hence avoiding integer overflow

            if(remain == 0)
                return i;
        }

        return -1;
    }
};
