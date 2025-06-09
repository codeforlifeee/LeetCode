class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> q;
        q.push(s);

        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                int size = q.size();
                while (size--) {
                    string curr = q.front();
                    q.pop();

                    // Lowercase version
                    curr[i] = tolower(curr[i]);
                    q.push(curr);

                    // Uppercase version
                    curr[i] = toupper(curr[i]);
                    q.push(curr);
                }
            }
        }
        vector<string> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
