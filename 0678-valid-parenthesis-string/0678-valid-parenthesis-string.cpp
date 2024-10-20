class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openstack;  
        stack<int> starstack;  
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openstack.push(i);
            } else if (s[i] == '*') {
                starstack.push(i);
            } else {
                // Handling ')'
                if (!openstack.empty()) {
                    openstack.pop();  
                } else if (!starstack.empty()) {
                    starstack.pop(); 
                } else {
                    return false;  
                }
            }
        }
        while (!openstack.empty() && !starstack.empty()) {
            if (openstack.top() < starstack.top()) {
                openstack.pop();
                starstack.pop();
            } else {
                return false;
            }
        }

        return openstack.empty();
    }
};
