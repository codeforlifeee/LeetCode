/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n-1; i++){
            ans = min(ans, abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};