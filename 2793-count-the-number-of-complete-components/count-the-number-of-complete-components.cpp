class Solution {
public:
    // DFS function to traverse a connected component and collect its properties
    void dfs(int u, std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
             int& vertices_count, int& sum_of_degrees) {
        
        visited[u] = true; // Mark current vertex as visited
        vertices_count++;  // Increment vertex count for this component
        sum_of_degrees += adj[u].size(); // Add degree of current vertex to sum_of_degrees
        
        // Recursively visit all unvisited neighbors
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, vertices_count, sum_of_degrees);
            }
        }
    }
    
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        // Build adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Ignore self-loops as they don't contribute to the 'completeness' definition
            // for distinct pairs of vertices. A single vertex (V=1) is complete with 0 edges.
            if (u == v) {
                continue; 
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        std::vector<bool> visited(n, false); // Keep track of visited vertices
        int complete_components_count = 0;   // Counter for complete components
        
        // Iterate through all vertices to find all connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Initialize counters for the current component
                int vertices_in_component = 0;
                int sum_of_degrees_in_component = 0;
                
                // Perform DFS to find all vertices and sum of degrees in this component
                dfs(i, adj, visited, vertices_in_component, sum_of_degrees_in_component);
                
                // Calculate the actual number of edges in the component
                // (Sum of degrees in an undirected graph is twice the number of edges)
                int edges_in_component = sum_of_degrees_in_component / 2;
                
                // For a component with V vertices to be complete, it must have V * (V - 1) / 2 edges.
                // Using long long for required_edges calculation to prevent potential overflow
                // if vertices_in_component is large, though for n=1000, int is sufficient.
                long long required_edges = static_cast<long long>(vertices_in_component) * (vertices_in_component - 1) / 2;
                
                // Check if the component is complete
                if (edges_in_component == required_edges) {
                    complete_components_count++;
                }
            }
        }
        
        return complete_components_count;
    }
};

