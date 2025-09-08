#include "Tree.hpp"
#include <queue>

TreeNode* buildTree(const std::vector<std::optional<int>>& vals) {
    if (vals.empty() || !vals[0]) return nullptr;

    TreeNode* root = new TreeNode(*vals[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (not q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < vals.size() and vals[i]) {
            curr->left = new TreeNode(*vals[i]);
            q.push(curr->left);
        }
        i++;

        if (i < vals.size() and vals[i]) {
            curr->right = new TreeNode(*vals[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}