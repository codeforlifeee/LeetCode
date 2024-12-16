class Solution {
public:
     typedef pair<int, int> P;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, P>, vector<pair<double, P>>, greater<pair<double, P>>> minHeap;
        
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                double value = (double)arr[i]/arr[j];  
                minHeap.push({value, {arr[i], arr[j]}});
            }
        }

        for (int i = 0;i < k-1;i++){
            minHeap.pop();  
        }
        pair<double, P> result = minHeap.top();
        return {result.second.first, result.second.second};
    }
};