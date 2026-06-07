class Solution {
public:
    int lengthOfLongestSubstring(string str) {
            int maxans = 0;

    for(int i = 0; i < str.length(); i++) {
        unordered_set<char> st;

        for(int j = i; j < str.length(); j++) {
            if(st.find(str[j]) != st.end())
                break;

            st.insert(str[j]);
            maxans = max(maxans, j - i + 1);
        }
    }

    return maxans;

        
    }
};