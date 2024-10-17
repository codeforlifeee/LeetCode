class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nextGreater;  // To store the next greater element for each number in nums2
        stack<int> s;  // To keep track of elements whose next greater element is not found yet

        // Traverse nums2 to build the next greater element map
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // If any elements remain in the stack, they don't have a next greater element
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }

        // Build the result for nums1 based on the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
        
    }
};