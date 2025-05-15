class Solution {
public:
    TreeNode* findLastRight(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* leftSubtree = root->left;
        TreeNode* rightmost = findLastRight(leftSubtree);
        rightmost->right = root->right;
        return leftSubtree;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) return helper(root);

        TreeNode* curr = root;
        while (curr) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
