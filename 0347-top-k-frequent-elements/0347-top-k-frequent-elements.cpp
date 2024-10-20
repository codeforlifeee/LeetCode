class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        for(int num : nums){
            freqMap[num]++;
        }
        vector<pair<int, int>>freqVec;
        for(const auto& entry : freqMap){
            freqVec.push_back({entry.second, entry.first});
        }
        
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, int>>());
        
        vector<int> result;
        for(int i = 0; i<k ;i++){
            result.push_back(freqVec[i].second);
        }
        return result;
        
    }
};