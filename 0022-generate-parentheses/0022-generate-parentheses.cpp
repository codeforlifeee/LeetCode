class Solution {
    
    
public:
    
   
    void gen(int n, int open, int close, string s, vector<string>& result) {
    
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            gen(n, open + 1, close, s + '(', result);
        }


        if (close < open) {
            gen(n, open, close + 1, s + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        gen(n, 0, 0, s, result); 
        return result;
    }
   
};