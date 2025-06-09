class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;
    //O(n)	O(w)	Most common, w = max width of tree
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            double level_sum = 0;

            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level_sum / level_size);
        }

        return result;
    }
};
