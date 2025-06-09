class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int min_depth = INT_MAX;

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            if (!node->left && !node->right) {
                min_depth = min(min_depth, depth);
            }

            if (node->left) {
                st.push({node->left, depth + 1});
            }
            if (node->right) {
                st.push({node->right, depth + 1});
            }
        }

        return min_depth;
    }
};
