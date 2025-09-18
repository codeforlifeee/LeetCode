class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        int n=s.size(), m=words.size(), len=words[0].size();
        unordered_map<string,int> count;
        for (auto &w: words) count[w]++;
        for (int i=0;i<len;i++) {
            int left=i, cnt=0;
            unordered_map<string,int> seen;
            for (int j=i;j+len<=n;j+=len) {
                string word=s.substr(j,len);
                if (count.count(word)) {
                    seen[word]++; cnt++;
                    while (seen[word]>count[word]) {
                        string leftWord=s.substr(left,len);
                        seen[leftWord]--; cnt--; left+=len;
                    }
                    if (cnt==m) ans.push_back(left);
                } else {
                    seen.clear(); cnt=0; left=j+len;
                }
            }
        }
        return ans;
    }
};
