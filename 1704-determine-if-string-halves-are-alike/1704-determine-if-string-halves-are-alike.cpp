class Solution {
public:
    
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    
    bool halvesAreAlike(string s) {
        
        
        int n = s.length();
        string str1 = s.substr(0, n / 2);
        string str2 = s.substr(n / 2);

        int vowelCount1 = 0, vowelCount2 = 0;

        for (char ch : str1) {
            if (isVowel(ch)) vowelCount1++;
        }

        for (char ch : str2) {
            if (isVowel(ch)) vowelCount2++;
        }
        
        return vowelCount1 == vowelCount2;
    }
};
