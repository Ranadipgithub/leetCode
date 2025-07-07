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
    void inorder(TreeNode *root, vector<int>&res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    TreeNode* buildTree(vector<int>&res, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode *newNode = new TreeNode(res[mid]);
        newNode->left = buildTree(res, low, mid-1);
        newNode->right = buildTree(res, mid+1, high);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return buildTree(res, 0, res.size()-1);
    }
};