class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occurrence(26, 0);
        for(int i = 0; i< s.length(); i++){
            last_occurrence[s[i]-'a'] = i;
        }

        vector<bool> visited(26, false);

        string result = "";
        for(int i = 0; i< s.length(); i++){
            char c = s[i];
            if(visited[c-'a']){
                continue;
            }

            while(!result.empty() && result.back() > c && last_occurrence[result.back() - 'a'] > i){
                visited[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c-'a'] = true;
        }
        return result;
    }
};