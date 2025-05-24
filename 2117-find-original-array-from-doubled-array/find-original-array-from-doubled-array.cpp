class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {}; 

        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        vector<int> original;

        for (int num : changed) {
            freq[num]++;
        }

        for (int num : changed) {
            if (freq[num] == 0) continue; 

            if (freq[num * 2] == 0) return {};

            original.push_back(num);
            freq[num]--;
            freq[num * 2]--;
        }

        return original;
    }
};
