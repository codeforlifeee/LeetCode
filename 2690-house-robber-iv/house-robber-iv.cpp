#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canRob(const vector<int>& nums, int k, int capability) {
        int count = 0, i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] <= capability) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = -1;
        int high = *max_element(nums.begin(), nums.end()) + 1;

        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (canRob(nums, k, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }
};
