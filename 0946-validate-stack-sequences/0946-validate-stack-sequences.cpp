class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j = 0;
        int n =pushed.size();
        for (int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};
