class Solution {
public:
    TreeNode* solve(vector<int> &preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    map<int, int> &mpp) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mpp[root->val];
        int numleft = inRoot - inStart;

        root->left = solve(preorder, preStart + 1, preStart + numleft,
                           inorder, inStart, inRoot - 1, mpp);

        root->right = solve(preorder, preStart + numleft + 1, preEnd,
                            inorder, inRoot + 1, inEnd, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return solve(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mpp);
    }
};
