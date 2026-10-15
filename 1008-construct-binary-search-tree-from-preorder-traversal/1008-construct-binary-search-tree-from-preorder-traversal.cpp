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
    TreeNode* solve(vector<int>&preorder, int start, int end){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(preorder[start]);
        int idx = end+1;
        for(int i = start+1;i<=end;i++){
            if(preorder[i] > preorder[start]){
                idx = i;
                break;
            }
        }
        root->left = solve(preorder, start+1, idx-1);
        if(idx != -1) root->right = solve(preorder, idx, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};