class Solution {
public:
    int maxScore(string s) {
        int n  = s.length();
        int result = INT_MIN;
        
        int total_ones = count(s.begin(), s.end(),'1');
        
        int zeroes = 0;
        int ones = 0;
        
        for(int i = 0; i<=n-2; i++){
            if(s[i] == '1') ones++;
            else zeroes++;
            
             int right_ones = total_ones - ones;
            
            result = max(result, zeroes + right_ones);
        }
        return result;
    }
};