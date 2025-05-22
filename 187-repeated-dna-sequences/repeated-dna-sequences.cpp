class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<string, int> count;
    vector<string> result;

    int n = s.length();
    if (n < 10) return {};

    for (int i = 0; i <= n - 10; i++) {
        string sub = s.substr(i, 10);
        count[sub]++;
        if (count[sub] == 2) { // Add to result only when it's seen the second time
            result.push_back(sub);
        }
    }
return result;


    }
};