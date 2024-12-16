class Solution {
public:
     typedef pair<int, int> P;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, P>> maxHeap;        
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                double value = (double)arr[i]/arr[j];  
                maxHeap.push({value, {arr[i], arr[j]}});
            }
        }

        while(maxHeap.size() > k){
            maxHeap.pop();  
        }
        pair<double, P> result = maxHeap.top();
        return {result.second.first, result.second.second};
    }
};