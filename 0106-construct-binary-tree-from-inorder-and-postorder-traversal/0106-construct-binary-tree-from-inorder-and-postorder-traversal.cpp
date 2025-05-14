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
    TreeNode* solve(vector<int> &postorder, int postStart, int postEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    map<int, int> &mpp) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root->val];
        int numleft = inRoot - inStart;

        root->left = solve(postorder, postStart, postStart + numleft - 1,
                           inorder, inStart, inRoot - 1, mpp);

        root->right = solve(postorder, postStart + numleft, postEnd - 1,
                            inorder, inRoot + 1, inEnd, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return solve(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mpp);
    }
};
