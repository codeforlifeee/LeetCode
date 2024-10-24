class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //store freq
        //if freq <= k //remove it
        //return the count  of element -1
         unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
         vector<int> frequencies;
        for (auto& [num, count] : freq) {
            frequencies.push_back(count);
        }
        sort(frequencies.begin(), frequencies.end());
        
         int uniqueElements = frequencies.size();
        for (int f : frequencies) {
            if (k >= f) {
                k -= f; 
                uniqueElements--;
            } else {
                break; 
            }
        }
        return uniqueElements;
    }
};