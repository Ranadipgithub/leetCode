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
    const int MOD = 1e9+7;
    long long maxi = 0;

    long long getTotalSum(TreeNode *node) {
        if (!node) return 0;
        return getTotalSum(node->left) + node->val + getTotalSum(node->right);
    }

    long long dfs(TreeNode *root, long long totalSum){
        if(root == NULL) return 0;

        long long left = dfs(root->left, totalSum);
        long long right = dfs(root->right, totalSum);

        long long subSum = root->val + left + right;

        maxi = max(maxi, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = getTotalSum(root);
        dfs(root, totalSum);
        return (int)(maxi % MOD);
    }
};