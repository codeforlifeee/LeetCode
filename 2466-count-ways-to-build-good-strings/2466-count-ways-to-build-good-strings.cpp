class Solution {
public:
    const int M = 1e9+7;
    int t[100001];
    int solve(int low, int high,int zero, int one,int l){
        
        if(l > high) return 0;
        
        if(t[l] != -1) return t[l];
        
        int count = (l >= low && l <= high) ? 1 : 0;
        
        int add0 = solve(low, high, zero, one, l + zero)%M;
        int add1 = solve(low, high, zero, one, l + one)%M;

        return t[l] = (count + add0 + add1)%M;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        memset(t,-1,sizeof(t));
        
        return solve(low,high,zero,one,0);
        
    }
};