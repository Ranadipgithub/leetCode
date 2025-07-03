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
    int solve(TreeNode *root, int &sum){
        if(root == NULL) return 0;
        int l = solve(root->left, sum);
        int r = solve(root->right, sum);
        int take_root_also = l + r + root->val;
        int any_one_good = root->val + max(l, r);
        int only_root = root->val;
        sum = max({sum, take_root_also, any_one_good, only_root});
        return max(any_one_good, only_root);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root, sum);
        return sum;
    }
};