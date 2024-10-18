class Solution {
public:
    string removeKdigits(string num, int k) {
        
         stack<char> st;

    // Iterate through each digit in the input string
    for (char digit : num) {
        // Remove the top of the stack if the current digit is smaller
        // and we still have more digits to remove
        while (!st.empty() && st.top() > digit && k > 0) {
            st.pop();
            k--;  // Decrease the count of digits to remove
        }
        // Push the current digit onto the stack
        st.push(digit);
    }

    // If there are still digits to remove, remove from the end of the stack
    while (k > 0) {
        st.pop();
        k--;
    }

    // Build the result from the stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Since we built the result in reverse order, reverse it back
    reverse(result.begin(), result.end());

    // Remove leading zeros
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    // If the result is empty, return "0"
    return result.empty() ? "0" : result;
        
    }
};