class Solution {
public:
    string removeOuterParentheses(string s) {
        int start = 0;
        int count = 0;
        string result = "";//initial string isme apan add krenge
        int n = s.size();
        
        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                count++;
            }else{
                count--;
            }
            
            if(count == 0){
                result += s.substr(start+1, i-start-1);
                start = i+1;
            }    
        }
        return result;
    }
};