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
    int diameter = 0;
    int calheight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lh = calheight(root->right);
        int rh =calheight(root->left);
        diameter = max(diameter, lh + rh );
        
        return 1 + max(lh,rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        calheight(root);
        
        return diameter;
        
    }
    
};