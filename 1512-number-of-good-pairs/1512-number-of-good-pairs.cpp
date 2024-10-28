class Solution {
public:
    static bool myComparator(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(), myComparator);
        
        int goodPairs = 0;
        for (int i = 0; i < freqVec.size(); i++) {
            int n = freqVec[i].second;
            if (n > 1) {
                goodPairs += (n * (n - 1)) / 2;
            }
        }

        return goodPairs;
    }
};
