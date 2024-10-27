class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        int max = *max_element(arr.begin(), arr.end());
        for(int i = 0; i< arr.size(); i++){
            if(arr[i] == max){
                ans = i;
            }
        }
        return ans;
    }
};