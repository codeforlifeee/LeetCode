class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    vector<int>digitsumarray(vector<int>nums){
        vector<int>res;
        int n = nums.size();
        for(int i = 0; i<n ;i++){
            res.push_back(digitsum(nums[i]));
        }
        return res;
    }
    
    int minSwaps(vector<int>& nums) {
        vector<int>arr = digitsumarray(nums);
        int n = nums.size();
        
        vector<tuple<int, int, int>> valueIndex(n);
        for (int i = 0; i < n; i++) {
            valueIndex[i] = {digitsum(nums[i]), nums[i], i};
        }

        sort(valueIndex.begin(), valueIndex.end());

        vector<pair<int, int>> position(n);
        for (int i = 0; i < n; i++) {
            position[i] = {nums[i], i};
        }

        vector<int> sortedToOriginal(n);
        for (int i = 0; i < n; i++) {
            sortedToOriginal[i] = get<2>(valueIndex[i]); 
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedToOriginal[i] == i)
                continue;

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = sortedToOriginal[j];
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += (cycle_size - 1);
        }
        return swaps;
    }
};