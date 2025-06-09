class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);  // Start BFS from the root

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);  // Add current node's value

                if (node->left) q.push(node->left);   // Enqueue left child
                if (node->right) q.push(node->right); // Enqueue right child
            }

            result.push_back(level);  // Store current level
        }

        return result;
    }
};

