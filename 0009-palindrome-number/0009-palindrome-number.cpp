class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }
    
    // Convert the integer to a string
    std::string str = std::to_string(x);
    
    // Create a reversed version of the string
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    // Compare the original string with the reversed string
    return str == reversedStr;
        
    }
};