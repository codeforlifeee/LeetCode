class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<char> characters;
        char ans=0;
        
        for(char ch: s){
            characters.push_back(ch);
        }
        
        for(char ch: t){
            characters.push_back(ch);
        }
        
        for(int i = 0;i<characters.size();i++){
            ans = ans ^ characters[i];
            
        }
        return ans;
        
    }
};