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
    vector<vector<int>> ans;
    void solve(TreeNode *root, int targetSum, vector<int>&v){
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum){
            ans.push_back(v);
        }
        solve(root->left, targetSum-root->val, v);
        solve(root->right, targetSum - root->val, v);

        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        vector<int> v;
        solve(root, targetSum, v);
        return ans;
    }
};