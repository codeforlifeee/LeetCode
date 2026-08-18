#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int x : nums) {
            counts[x]++;
        }

        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : counts) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }

        if (k == n) {
            int ans = -1;
            for (int x : nums) {
                ans = max(ans, x);
            }
            return ans;
        }

        int ans = -1;
        if (counts[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
