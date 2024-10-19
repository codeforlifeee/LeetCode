class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        unordered_map<char,int> countMap;//keeps track of count of a,b,c
        int left = 0;
        int result = 0;
        
        for(int right = 0; right<n; right ++){
            countMap[s[right]]++;
            
            while(countMap['a']>0 && countMap['b']>0 && countMap['c']>0){
                result += (n-right);
                countMap[s[left]]--;
                
                left++;
            }
        }
        return result;
        
        
    }
};