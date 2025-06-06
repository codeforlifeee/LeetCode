class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;

    // up[i] = length of increasing sequence ending at index i
    // down[i] = length of decreasing sequence starting at index i
    vector<int> up(n, 0), down(n, 0);

    // First pass (left to right): compute up[]
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1])
            up[i] = up[i - 1] + 1;
    }

    // Second pass (right to left): compute down[]
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1])
            down[i] = down[i + 1] + 1;
    }

    int longest = 0;

    // Third pass: check valid mountains
    for (int i = 0; i < n; ++i) {
        if (up[i] > 0 && down[i] > 0) {
            longest = max(longest, up[i] + down[i] + 1);
        }
    }

    return longest;

    /*
     * Time Complexity: O(n)
     * - First pass to fill up[]: O(n)
     * - Second pass to fill down[]: O(n)
     * - Third pass to compute result: O(n)
     * => Total: O(n)
     *
     * Space Complexity: O(n)
     * - Two extra arrays: up[] and down[]
     */
    }
};