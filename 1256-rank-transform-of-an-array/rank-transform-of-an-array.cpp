class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int,int> ranks;

        int rank = 1;

        for(int num : temp){
            if(ranks.find(num) == ranks.end()){
                ranks[num] = rank++;
            }
        }    

        for(int &num : arr){
            num = ranks[num];
        }
        return arr;
    }
};