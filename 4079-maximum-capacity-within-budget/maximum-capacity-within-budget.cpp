class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
         int n = costs.size();
    
    // Create pairs of (cost, capacity) and sort by cost
    vector<pair<int, int>> machines(n);
    for (int i = 0; i < n; i++) {
        machines[i] = {costs[i], capacity[i]};
    }
    sort(machines.begin(), machines.end());
    
    int maxCapacity = 0;
    
    // Case 1: Select only one machine
    for (int i = 0; i < n; i++) {
        if (machines[i].first < budget) {
            maxCapacity = max(maxCapacity, machines[i].second);
        }
    }
    
    // Build prefix max capacity array
    vector<int> maxCapUpTo(n);
    maxCapUpTo[0] = machines[0].second;
    for (int i = 1; i < n; i++) {
        maxCapUpTo[i] = max(maxCapUpTo[i-1], machines[i].second);
    }
    
    // Case 2: For each machine r, find best machine l (l < r) to pair with
    for (int r = 1; r < n; r++) {
        int maxCost = budget - machines[r].first - 1;
        
        // Binary search for rightmost position with cost <= maxCost
        int l = -1;
        int left = 0, right = r - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (machines[mid].first <= maxCost) {
                l = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (l >= 0) {
            maxCapacity = max(maxCapacity, machines[r].second + maxCapUpTo[l]);
        }
    }
    
    return maxCapacity;
   
    }
};