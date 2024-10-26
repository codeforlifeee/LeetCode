class Solution {
public:
    
    bool isvowel(char &ch){
        return ch == 'a'||ch =='e'|| ch == 'i'||ch =='o'|| ch =='u';
    
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int result = 0;
        for(int i = 0; i<n; i++){
            int vowel  = 0;
            int con = 0;
            for(int j = i; j<n; j++){
                if(isvowel(s[j])){
                    vowel++;
                }else{
                    con++;
                }
                
                
                
                if(vowel == con && (vowel*con)%k ==0){
                    result++;
                }
            }
        }
     return result;   
    }
    
};