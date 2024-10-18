class Solution {
public:
    string removeKdigits(string num, int k) {
        
         stack<char> st;
    for (char digit : num) {
       
        while (!st.empty() && st.top() > digit && k > 0) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result.empty() ? "0" : result;
        
    }
};