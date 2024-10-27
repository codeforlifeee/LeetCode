class Solution {
public:
     int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0;
       //You can remove i < n-1 check because array is gauranteed to be Mountain (given in qn)
        while(i < n-1 && arr[i] < arr[i+1])
            i++;
        
        return i;
    }
};