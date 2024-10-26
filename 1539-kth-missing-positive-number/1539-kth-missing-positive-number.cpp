class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int missingCount = 0;  
        int current = 1;     
        int i = 0;             

        while (missingCount < k) {
            if (i < arr.size() && arr[i] == current) {
    
                i++;
            } else {
                missingCount++;
            }
            current++;
        }
        return current - 1;
        
    }
};