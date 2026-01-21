#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Store in sets
        set<pair<int, int>> oddSet;   // {frequency, character index}
        set<pair<int, int>> evenSet;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            if (freq[i] % 2 == 1) {
                oddSet.insert({freq[i], i});
            } else {
                evenSet.insert({freq[i], i});
            }
        }

        // Step 3: Check validity
        if (oddSet.empty() || evenSet.empty()) {
            return 0;
        }

        // Step 4: Get max odd and min even
        int maxOdd = prev(oddSet.end())->first;
        int minEven = evenSet.begin()->first;

        return maxOdd - minEven;
    }
};
