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
    void mark(TreeNode *root, TreeNode *&prev, TreeNode *&start, TreeNode *&end){
        if(!root) return;
        mark(root->left, prev, start, end);
        if(prev){
            if(root->val < prev->val){
                if(!start) start = prev;
                end = root;
            }
        }
        prev = root;
        mark(root->right, prev, start, end);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *start = nullptr, *end = nullptr, *prev = nullptr;
        mark(root, prev, start, end);
        swap(start->val, end->val);
        return;
    }
};