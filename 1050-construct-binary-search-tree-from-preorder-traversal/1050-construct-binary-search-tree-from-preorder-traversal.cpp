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
    TreeNode *solve(vector<int> &pre, int preStart, int preEnd, vector<int>&in, int inStart, int inEnd, unordered_map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(pre[preStart]);
        int inRoot = mpp[root->val];
        int numsLeft = inRoot-inStart;
        root->left = solve(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, mpp);
        root->right = solve(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, mpp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> pre = preorder;
        sort(preorder.begin(), preorder.end());
        vector<int> in = preorder;
        unordered_map<int, int> mpp;
        for(int i = 0;i<in.size();i++){
            mpp[in[i]] = i;
        }
        return solve(pre, 0, pre.size()-1, in, 0, in.size()-1, mpp);
    }
};