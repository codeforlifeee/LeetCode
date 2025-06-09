#include <unordered_set>

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);

        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(k - num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }

private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
