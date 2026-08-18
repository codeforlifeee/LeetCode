class Solution {
public:
    string simplifyPath(string path) {
        vector<string> segments;
        string temp = "";
        path += "/";
        
        for (char ch : path) {
            if (ch == '/') {
                if (temp == "..") {
                    if (!segments.empty()) {
                        segments.pop_back();
                    }
                } else if (temp != "." && !temp.empty()) {
                    segments.push_back(temp);
                }
                temp = "";
            } else {
                temp += ch;
            }
        }
        
        string simplified = "";
        for (const string& segment : segments) {
            simplified += "/" + segment;
        }
        
        return simplified.empty() ? "/" : simplified;
    }
};