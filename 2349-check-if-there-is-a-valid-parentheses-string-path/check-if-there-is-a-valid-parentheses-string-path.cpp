#include <vector>
using namespace std;
class Solution {
private:
    int m, n;
    vector<vector<vector<int>>> memo;
    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid) {
        // If the current balance is less than 0, it's invalid.
        if (bal < 0) return false;
        
        // Remaining steps to reach the bottom-right corner
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        
        // If the balance is greater than the remaining steps, we can't reduce it to 0.
        // Also, the parity of bal and remaining_steps must match.
        if (bal > remaining_steps || (remaining_steps - bal) % 2 != 0) {
            return false;
        }
        // If we reached the destination, check if the path is fully balanced
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }
        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }
        bool possible = false;
        
        // Move Down
        if (r + 1 < m) {
            int next_bal = bal + (grid[r + 1][c] == '(' ? 1 : -1);
            possible = possible || dfs(r + 1, c, next_bal, grid);
        }
        
        // Move Right
        if (c + 1 < n) {
            int next_bal = bal + (grid[r][c + 1] == '(' ? 1 : -1);
            possible = possible || dfs(r, c + 1, next_bal, grid);
        }
        return memo[r][c][bal] = possible;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // If start is ')' or end is '(', it's impossible to form a valid path
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        // Total path length is m + n - 1. For a balanced parentheses string, length must be even.
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        // Max possible balance is (m + n) / 2
        int max_bal = (m + n) / 2;
        memo.assign(m, vector<vector<int>>(n, vector<int>(max_bal + 1, -1)));
        return dfs(0, 0, 1, grid);
    }
};
