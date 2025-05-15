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
    TreeNode *prev = nullptr;
    void dfs(TreeNode *root, int &mini){
        if(root == nullptr) return;
        dfs(root->left, mini);
        if(prev){
            mini = min(mini, abs(root->val - prev->val));
        }
        prev = root;
        dfs(root->right, mini);
    }
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return 0;
        int mini = INT_MAX;
        dfs(root, mini);
        return mini;
    }
};