class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while (!que.empty()) {
            int n = que.size();
            vector<TreeNode*> levelNodes;

            for (int i = 0; i < n; ++i) {
                TreeNode* temp = que.front();
                que.pop();
                levelNodes.push_back(temp);

                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }

            if (level % 2 == 1) {
                int i = 0, j = levelNodes.size() - 1;
                while (i < j) {
                    int tempVal = levelNodes[i]->val;
                    levelNodes[i]->val = levelNodes[j]->val;
                    levelNodes[j]->val = tempVal;
                    ++i;
                    --j;
                }
            }
            ++level;
        }
        return root;
    }
};
