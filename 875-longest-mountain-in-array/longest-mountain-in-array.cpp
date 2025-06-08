class Solution {
public:
    int longestMountain(vector<int>& arr) {
            int n = arr.size();
    int maxLen = 0;
    int i = 1;

    while (i < n - 1) {
        // Check if current element is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand to the left
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            // Expand to the right
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);

            // Move i to the end of the current mountain
            i = right;
        } else {
            i++;
        }
    }

    return maxLen;

        
    }
};