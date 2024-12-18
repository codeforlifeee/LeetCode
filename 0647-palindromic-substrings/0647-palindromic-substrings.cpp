class Solution {
public:
    int t[1001][1001];
    
    bool check(string &s, int i, int j){
        if(i > j) return true;
        
        if(t[i][j] != -1) return t[i][j]; //0 : false 1: true
        
        if(s[i] == s[j]) return t[i][j] = check(s, i+1, j-1);
        
        return t[i][j] = false;
    }
    
    int countSubstrings(string s) {
        
        memset(t,-1,sizeof(t));
        //t[i][j] = -1: not solved yet
        //t[i][j] = 0 : False
        //t[i][j] = 1 : True
        
        
        int n = s.length();
        int count = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                
                if(check(s,i,j)){
                    count++;
                }
            }
        }
        return count;
        
    }
};