class Solution {
public:
    void findLeaf(TreeNode *root, vector<int>& leaf) {
        if (root == NULL) return;
        if (!root->left && !root->right) {
            leaf.push_back(root->val);
            return;
        }
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        findLeaf(root1, leaf1);
        findLeaf(root2, leaf2);
        return leaf1 == leaf2;
    }
};
