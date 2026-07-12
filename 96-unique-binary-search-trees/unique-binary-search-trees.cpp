class Solution {
public:
    int numTrees(int n) {
        vector<int> bst_counts(n+1, 0);

        bst_counts[0] =1;
        bst_counts[1] = 1;

        for(int nodes = 2; nodes <= n; nodes++){
            for(int root = 1; root <= nodes;root++){
                int left_combinations = bst_counts[root-1];
                int right_combinations = bst_counts[nodes-root];

                bst_counts[nodes] += left_combinations * right_combinations;
            }
        }
        return bst_counts[n];
    }
};