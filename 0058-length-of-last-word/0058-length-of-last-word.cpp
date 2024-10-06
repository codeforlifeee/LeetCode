class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, temp = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
                res = 0;
            } else
                res++;
            if (s[i] != ' ' && (s[i + 1] == ' ' || i + 1 == s.length())) {
                temp = res;
            }
        }
        return temp;
    }
};