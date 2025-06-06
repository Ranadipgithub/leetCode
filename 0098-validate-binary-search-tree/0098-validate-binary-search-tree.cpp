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
    void inOrder(TreeNode *root, vector<int>&res){
        if(root == nullptr) return;

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    TreeNode *prev = nullptr;
    bool inorder(TreeNode *root){
        if(!root) return true;
        if(!inorder(root->left)) return false;
        if(prev && root->val <= prev->val) return false;
        prev = root;
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
        // vector<int> res;
        // inOrder(root, res);
        // bool fg = true;
        // for(int i = 1;i<res.size();i++){
        //     if(res[i-1]>=res[i]){
        //         fg = false;
        //         break;
        //     }
        // }
        // return fg;
    }
};