class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        
        for(int &x : tasks) {
            freq[x]++;
        }
        
        int ans = 0;
        
        for(auto &it : freq) {
            int count = it.second;
            
            if(count == 1)
                return -1;
            
            if(count % 3 == 0)
                ans += count/3;
            else
                ans += count/3+1;
        }
        
        return ans;
        
    }
};