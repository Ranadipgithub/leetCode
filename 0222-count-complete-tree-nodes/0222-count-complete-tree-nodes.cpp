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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLH(root);
        int rh = findRH(root);

        if(lh == rh) return (1<<lh)-1;

        return 1+countNodes(root->left) + countNodes(root->right);
    }

    int findLH(TreeNode *root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }

    int findRH(TreeNode *root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
};