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
private:
    int height(TreeNode* root, bool &valid){
        if(root == nullptr) return 0;
        int lh = height(root->left, valid);
        int rh = height(root->right, valid);
        if(abs(lh-rh) > 1) valid = 0;
        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool valid = 1;
        height(root, valid);
        return valid;
    }
};