class Solution {
public:
     vector<char> processString(const string& str) {
        vector<char>result;
        for (char ch : str) {
            if (ch == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        vector<char> sv1 = processString(s);
        vector<char> sv2 = processString(t);
        return sv1 == sv2;
    }
   
};