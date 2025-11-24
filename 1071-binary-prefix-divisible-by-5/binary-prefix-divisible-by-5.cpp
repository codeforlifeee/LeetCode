class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
            vector<bool> ans;
    
    int nextState[5][2] = {
        {0, 1}, // from remainder 0: adding 0 -> 0, adding 1 -> 1
        {2, 3}, // from remainder 1
        {4, 0}, // from remainder 2
        {1, 2}, // from remainder 3
        {3, 4}  // from remainder 4
    };

    int state = 0;
    for (int bit : nums) {
        state = nextState[state][bit];
        ans.push_back(state == 0);
    }

    return ans;

        
    }
};