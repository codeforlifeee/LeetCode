class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";  // If t is larger than s, no solution exists

        unordered_map<char, int> tFreq;  // Store frequency of characters in t
        unordered_map<char, int> windowFreq;  // Store frequency of characters in the current window

        // Fill frequency map for t
        for (char c : t) tFreq[c]++;

        int required = tFreq.size();  // Total distinct characters required
        int formed = 0;  // Characters in the current window matching required frequency

        int left = 0, right = 0;  // Pointers for the sliding window
        int minLen = INT_MAX;  // Store the length of the smallest valid window
        int start = 0;  // Store the starting index of the smallest valid window

        while (right < s.size()) {
            char c = s[right];  // Add the character at right pointer to the window
            windowFreq[c]++;

            // If the current character's frequency matches the required frequency in t
            if (tFreq.find(c) != tFreq.end() && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try to contract the window from the left
            while (formed == required) {
                if (right - left + 1 < minLen) {  // Update minimum window length
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];  // Character at the left pointer
                windowFreq[leftChar]--;  // Reduce its frequency

                // If frequency no longer matches what's required in t, decrease `formed`
                if (tFreq.find(leftChar) != tFreq.end() && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }

                left++;  // Move the left pointer to shrink the window
            }

            right++;  // Expand the window by moving the right pointer
        }

        // If no valid window was found, return an empty string
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};