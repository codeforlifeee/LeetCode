#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        
        // Step 1: Calculate how many fill characters are needed
        int rem = len % k;
        if (rem != 0) {
            int need = k - rem;
            s.append(need, fill);
        }
        
        // Step 2: Divide string into groups of size k
        vector<string> result;
        for (int i = 0; i < s.length(); i += k) {
            result.push_back(s.substr(i, k));
        }
        
        return result;
    }
};
