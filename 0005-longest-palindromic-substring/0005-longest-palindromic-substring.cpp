class Solution {
public:
    string longestPalindrome(string s) {
          if (s.empty()) return "";

        int start = 0, maxLength = 1; // Start of the longest palindrome and its length

        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindromes (single character center)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (two character center)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Take the maximum length of the two
            int len = max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2; // Update the start index
            }
        }
        
        return s.substr(start, maxLength); // Extract the longest palindromic substring
        
    }
    private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1; // Length of the palindrome
    }
    
    
    
};