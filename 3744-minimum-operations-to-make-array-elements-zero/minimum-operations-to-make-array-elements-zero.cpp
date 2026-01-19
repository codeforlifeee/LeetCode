class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long steps = 0;

            long long start = 1, cost = 1;

            while (start <= r) {
                long long end = 4 * start - 1;

                long long L = max(start, l);
                long long R = min(end, r);

                if (L <= R) {
                    steps += (R - L + 1) * cost;
                }

                start *= 4;
                cost++;
            }

            ans += (steps + 1) / 2;   // ceil(steps/2)
        }
        return ans;
    }
};
