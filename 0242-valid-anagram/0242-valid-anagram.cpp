class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        for(char &ch : s){
            count[ch-'a']++;
        }
        for(char &ch : t){
            count[ch-'a']--;
        }
        
        int countzero = 0;
        
        for(int i = 0; i<count.size(); i++){
            if(count[i] == 0) countzero++;
        }
        
        return countzero ==count.size();
        
       
    }
};