class Solution {
public:
    int n;
    const int M = 1e9+7;
    long long t[100001];
    
    int solve(int start, string &s, int &k){
       if(start >= n) return 1;
        
       if(s[start] == '0') return 0;
        
        if(t[start] != -1) return t[start];
        
        long long ans =0;
        long long num = 0;
        
        for(int end = start; end<n; end++){
            num = (num*10) + (s[end]-'0');
            
            if(num > k) break;
            
            ans = (ans%M + solve(end + 1, s, k)%M)%M;
        }
        return t[start] = ans%M;
        
    }
    int numberOfArrays(string s, int k) {
        
        n = s.length();
        
        memset(t,-1,sizeof(t));
        
        return solve(0,s,k);
        
    }
};