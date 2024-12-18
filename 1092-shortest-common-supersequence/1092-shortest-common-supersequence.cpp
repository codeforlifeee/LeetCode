class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // DP table initialization
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        // Filling the DP table
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = i + j;
                } else if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        // Constructing the result string from the DP table
        string result = "";
        int i = m, j = n;
        
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                i--;
                j--;
            } else {
                if(t[i-1][j] < t[i][j-1]) {
                    result.push_back(s1[i-1]);
                    i--;
                } else {
                    result.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        
        // Add the remaining characters of s1 or s2
        while(i > 0) {
            result.push_back(s1[i-1]);
            i--;
        }
        while(j > 0) {
            result.push_back(s2[j-1]);
            j--;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};