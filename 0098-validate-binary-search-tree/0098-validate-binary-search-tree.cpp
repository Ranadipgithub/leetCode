class Solution {
public:
    bool inorder(TreeNode* root, long long& prev) {
        if (!root) return true;
        if (!inorder(root->left, prev)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return inorder(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN; 
        return inorder(root, prev);
    }
};
