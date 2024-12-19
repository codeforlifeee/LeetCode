class Solution {
public:
    string largestGoodInteger(string num) {
       vector<string>req = {"999", "888","777","666","555","444","333","222","111","000"};
        
        for(const string& s : req){
            for(int i = 0;i<=num.length()-3;i++){
                if(num.substr(i, 3) == s){
                    return s;
                }
            }
        }
        return "";
    }
};