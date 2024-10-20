class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openstack;  // Stack to store the indices of '('
        stack<int> starstack;  // Stack to store the indices of '*'
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openstack.push(i);
            } else if (s[i] == '*') {
                starstack.push(i);
            } else {
                // Handling ')'
                if (!openstack.empty()) {
                    openstack.pop();  // Use '(' to match ')'
                } else if (!starstack.empty()) {
                    starstack.pop();  // Use '*' to match ')'
                } else {
                    return false;  // No matching '(' or '*'
                }
            }
        }

        // Handle remaining '(' and '*'
        while (!openstack.empty() && !starstack.empty()) {
            if (openstack.top() < starstack.top()) {
                openstack.pop();
                starstack.pop();
            } else {
                return false;  // Invalid if '(' index is greater than '*' index
            }
        }

        // If there are no unmatched '(', return true
        return openstack.empty();
    }
};
