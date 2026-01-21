#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxFreeTime(long long eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        // Step 1: Compute gaps
        vector<long long> gaps;
        gaps.push_back(startTime[0] - 0);  // before first meeting
        
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        
        gaps.push_back(eventTime - endTime[n - 1]);  // after last meeting
        
        // Step 2: Sliding window of size k+1
        long long windowSum = 0, maxFree = 0;
        int windowSize = k + 1;
        
        for (int i = 0; i < gaps.size(); i++) {
            windowSum += gaps[i];
            
            if (i >= windowSize) {
                windowSum -= gaps[i - windowSize];
            }
            
            if (i >= windowSize - 1) {
                maxFree = max(maxFree, windowSum);
            }
        }
        
        return maxFree;
    }
};
