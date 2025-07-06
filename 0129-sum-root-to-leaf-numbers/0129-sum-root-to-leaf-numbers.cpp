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
    int sum = 0;
    void findPathSum(TreeNode *root, string s){
        if(root == NULL) return;
        s += to_string(root->val);
        if(!root->left && !root->right){
            sum += stoi(s);
            return;
        }
        else {
            if(root->left) findPathSum(root->left, s);
            if(root->right) findPathSum(root->right, s);
        }
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        findPathSum(root, s);
        return sum;
    }
};