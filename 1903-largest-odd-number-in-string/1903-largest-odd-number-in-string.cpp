class Solution {
public:
    string largestOddNumber(string num) {
         int index = num.length() - 1;

        // num[index] - '0'//char to int
        // & 1 checks whether or not the number is odd
        while (index >= 0 && ((num[index] - '0') & 1) == 0) --index;

        // return the substring we found based on the index we stopped at
        return num.substr(0, index + 1);
        
    }
};