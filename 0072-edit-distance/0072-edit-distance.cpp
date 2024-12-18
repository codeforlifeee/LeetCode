class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));

        // Fill DP table
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                // If one of the strings is empty
                if(i == 0 || j == 0) {
                    t[i][j] = i + j;
                }
                // If characters match, no operation needed
                else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                }
                // If characters don't match, take the minimum of the three possible operations
                else {
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
                }
            }
        }
        // The answer is in the bottom-right cell
        return t[m][n];
    }
};
