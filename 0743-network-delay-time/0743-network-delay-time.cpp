class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec : times) {
            
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	    vector<int> result(n+1, INT_MAX);

	result[k] = 0;
	pq.push({0, k});

	while(!pq.empty()) {

	    int d  = pq.top().first;
	    int node = pq.top().second;
	    pq.pop();

	    for(auto &vec : adj[node]) {

		int adjNode = vec.first;
		int dist    = vec.second;

		if(d + dist < result[adjNode]) {

		    result[adjNode] = d + dist;
		    pq.push({d+dist, adjNode});

		}

	    }

	}
        int maxTime = *max_element(result.begin() + 1, result.end());
        
        return maxTime == INT_MAX ? -1 : maxTime;
        
    }
};