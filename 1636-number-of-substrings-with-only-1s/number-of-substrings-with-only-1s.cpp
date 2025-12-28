class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> blocks;
        long long count = 0;

        // Step 1: collect consecutive 1s
        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                if (count > 0) {
                    blocks.push_back(count);
                    count = 0;
                }
            }
        }
        if (count > 0) {
            blocks.push_back(count);
        }

        // Step 2: calculate substrings
        long long ans = 0;
        for (long long n : blocks) {
            ans = (ans + (n * (n + 1)) / 2) % MOD;
        }

        return ans;
    }
};
