class Solution {
public:
    
    int countPartitions(vector<int>& a, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        long long high = accumulate(a.begin(), a.end(), 0LL);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(a, mid);

            if (partitions > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
        
    }
};