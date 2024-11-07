class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for(int i = 0; i<24; i++){
            int countith = 0;
            for(int &num : candidates){
                if((num & (1<<i)) != 0){
                    countith++;
                }
            }
            result = max(result, countith);
        }
        return result;
    }
};