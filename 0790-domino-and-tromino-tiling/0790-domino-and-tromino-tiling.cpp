class Solution {
public:
    int M = 1e9 + 7;
    int t[1001]; 

    int solve(int n) {
        if (n <= 2) {
            return n; 
        }
        if(n==3) return 5;

        if (t[n] != -1) {
            return t[n];
        }

        t[n] = (2 * solve(n - 1) % M + solve(n - 3) % M) % M; 
        return t[n];
    }

    int numTilings(int n) {
        memset(t, -1, sizeof(t)); 
        return solve(n);
    }
};