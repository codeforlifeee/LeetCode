class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;

    // Filter the string: keep only alphanumeric characters and convert to lowercase
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }

    // Check if filtered string is a palindrome
    int left = 0, right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
        
    }
};