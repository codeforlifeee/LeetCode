class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while(right < s.length()) {
        if(seen.find(s[right]) == seen.end()) {
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            //dikh gaya toh erase krdo left++
            seen.erase(s[left]);
            left++;
        }
    }
    return maxLen;
    }
};
