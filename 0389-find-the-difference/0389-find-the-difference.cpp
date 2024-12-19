class Solution {
public:
    char findTheDifference(string s, string t) {
        int sn = 0, tn = 0;
        for(char ch: s){
            sn = sn + (int)ch;
        }
        for(char ch: t){
            tn = tn + (int)ch;
        }
        
        return char(tn-sn);
        
    }
};