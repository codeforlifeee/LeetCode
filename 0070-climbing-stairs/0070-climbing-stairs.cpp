class Solution {
public:
    int t[46];
    int solve(int n){
        
        if(t[n] != -1){
            return t[n];
        }
         
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        
        return t[n] = solve(n-1) + solve(n-2);
    }
   
    int climbStairs(int n) {
        
        memset(t,-1, sizeof(t));     
        return solve(n);
    }
};