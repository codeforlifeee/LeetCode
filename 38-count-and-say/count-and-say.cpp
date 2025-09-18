class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string prev=countAndSay(n-1), ans="";
        for (int i=0;i<prev.size();) {
            int j=i;
            while (j<prev.size() && prev[j]==prev[i]) j++;
            ans+=to_string(j-i)+prev[i];
            i=j;
        }
        return ans;
    }
};
