class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even0 = 0, odd0 = 0; // mod = 0
        int even1 = 0, odd1 = 0; // mod = 1

        for (int x : nums) {
            if (x % 2 == 0) {
                // mod = 0 (same parity)
                even0 = even0 + 1;

                // mod = 1 (different parity)
                even1 = odd1 + 1;
            } else {
                // mod = 0 (same parity)
                odd0 = odd0 + 1;

                // mod = 1 (different parity)
                odd1 = even1 + 1;
            }
        }

        return max({even0, odd0, even1, odd1});
    }
};
