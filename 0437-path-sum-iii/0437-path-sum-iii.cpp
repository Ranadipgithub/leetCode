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
    int solve(TreeNode* root, long long target) {
        if (root == nullptr) return 0;

        int cnt = 0;
        if (root->val == target) cnt++;

        cnt += solve(root->left, target - root->val);
        cnt += solve(root->right, target - root->val);

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        return solve(root, (long long)targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};
