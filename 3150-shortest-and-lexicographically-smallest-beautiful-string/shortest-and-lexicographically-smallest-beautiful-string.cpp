class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.length();
        vector<int>pos;

        for(int i = 0; i< n; i++){
            if(s[i] == '1'){
                pos.push_back(i);
            }
        }

        if(pos.size() < k){
            return "";
        }

        int min_len = n+1;
        string ans = "";

        for(size_t i  =0;  i <= pos.size()-k; i++){
            int len = pos[i+k-1] - pos[i] + 1;

            if(len < min_len){
                min_len = len;
                ans = s.substr(pos[i], len);
            }else if(len == min_len){
                string current = s.substr(pos[i], len);

                if(current < ans){
                    ans = current;
                }
            }
        }

        return ans;
    }
};