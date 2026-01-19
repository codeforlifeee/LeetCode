class Solution {
private:
    int n;
    map<int, vector<int>> diag;

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        // Step 1: Group elements by diagonal (i - j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort each diagonal
        for (auto &it : diag) {
            if (it.first >= 0)
                sort(it.second.begin(), it.second.end(), greater<int>()); // bottom-left
            else
                sort(it.second.begin(), it.second.end()); // top-right
        }

        // Step 3: Put values back into grid
        map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }
        }

        return grid;
    }
};
