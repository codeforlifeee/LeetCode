class Solution {
public:
    const int MOD = 1e9 + 7;

    long long get_hash(string s) {
        sort(s.begin(), s.end()); 
        long long h = 0;
        for (char c : s) {
            h = (h * 31 + (c - 'a' + 1)) % MOD;
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> hashMap;

        for (const string& word : strs) {
            long long h = get_hash(word);
            hashMap[h].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : hashMap) {
            result.push_back(pair.second);
        }

        return result;
 
    }
};