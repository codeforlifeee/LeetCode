class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> s;
        for (int i=0;i<n;i+=1){
            for (int j=0;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> s1;
        for (int x: s){
            for (int i=0;i<n;i++){
                s1.insert(x^nums[i]);
            }
        }
        return s1.size();
    }
};

