class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
         vector<int> startt, endt;
        for (const auto& flower : flowers) {
            startt.push_back(flower[0]); 
            endt.push_back(flower[1]); 
        }
        sort(startt.begin(), startt.end());
        sort(endt.begin(), endt.end());
        
        vector<int> ans(people.size(), 0);
        
        for (int i = 0; i < people.size(); i++) {
            int currentTime = people[i];
        
            int bloomCount = upper_bound(startt.begin(), startt.end(), currentTime) - startt.begin();
            int wiltCount = lower_bound(endt.begin(), endt.end(), currentTime) - endt.begin();
            ans[i] = bloomCount - wiltCount; 
        }
        
        return ans;
        
    }
};