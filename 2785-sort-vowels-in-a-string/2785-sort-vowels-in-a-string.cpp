class Solution {
public:
     string sortVowels(string s){
        vector<char>vowels;
        for (char ch : s){
            if (isVowel(ch)){
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for (char& ch : s) {
            if (isVowel(ch)) {
                ch = vowels[index++];
            }
        }
        return s;
    }


    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};