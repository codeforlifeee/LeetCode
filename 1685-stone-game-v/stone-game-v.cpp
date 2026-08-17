#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[501][501];
    vector<int> pref;

    int solve(const vector<int>& stoneValue, int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int max_score = 0;
        int total_sum = pref[j + 1] - pref[i];
        int left_sum = 0;

        for (int k = i; k < j; ++k) {
            left_sum += stoneValue[k];
            int right_sum = total_sum - left_sum;

            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + solve(stoneValue, i, k));
            } else if (left_sum > right_sum) {
                max_score = max(max_score, right_sum + solve(stoneValue, k + 1, j));
            } else {
                max_score = max(max_score, left_sum + max(solve(stoneValue, i, k), solve(stoneValue, k + 1, j)));
            }
        }

        return memo[i][j] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        memset(memo, -1, sizeof(memo));
        return solve(stoneValue, 0, n - 1);
    }
};
