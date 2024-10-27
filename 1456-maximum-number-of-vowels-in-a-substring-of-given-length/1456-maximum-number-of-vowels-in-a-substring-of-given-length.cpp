class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int maxCount = 0, currentCount = 0;

        //vowel in first window of k 
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                currentCount++;
            }
        }
        maxCount = currentCount;

        //for rest of the string
        for (int i = k; i < s.length(); ++i) {
            //removing and adding 
            if (isVowel(s[i - k])) {
                currentCount--;
            }
            if (isVowel(s[i])) {
                currentCount++;
            }
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
};
