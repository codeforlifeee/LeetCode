class Solution {
public:
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    int left = 0, right = 0, currentSum = 0, maxFruits = 0;
    // Sliding window over fruits: O(N) time
    for (right = 0; right < fruits.size(); ++right) {
        currentSum += fruits[right][1];
        // Shrink window if cost exceeds k: O(N) amortized
        while (left <= right) {
            int leftPos = fruits[left][0];
            int rightPos = fruits[right][0];
            int distToLeft = abs(startPos - leftPos);
            int distToRight = abs(startPos - rightPos);
            int steps = min(distToLeft, distToRight) + (rightPos - leftPos);
            // Tracing Iteration: left=0, right=2, steps=3 <= 4
            if (steps <= k) break;
            currentSum -= fruits[left][1];
            left++;
        }
        maxFruits = max(maxFruits, currentSum);
    }
    return maxFruits;
}
};