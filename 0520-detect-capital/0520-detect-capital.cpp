class Solution {
public:
    bool allCapital(const string& word) {
        int n = word.length();
        for (char ch : word) {
            if (ch < 'A' || ch > 'Z') {
                return false;
            }
        }
        return true;
    }
    
    bool allSmall(const string& word) {
        int n = word.length();
        for (char ch : word) {
            if (ch < 'a' || ch > 'z'){ 
                return false;
            }
        }
        return true;
    }

    bool firstCapitalRestSmall(string& word) {
        int n = word.length();
        if (n == 0) return false; 
        if (word[0] < 'A' || word[0] > 'Z') return false;
        
    
        for (int i = 1; i < n; i++) {
            if (word[i] < 'a' || word[i] > 'z'){
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string& word) {
        return allCapital(word) || allSmall(word) || firstCapitalRestSmall(word);
    }
};