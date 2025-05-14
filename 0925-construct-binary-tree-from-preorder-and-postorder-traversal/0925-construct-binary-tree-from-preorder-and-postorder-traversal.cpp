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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postorder, int postStart,
                    unordered_map<int, int>& mpp) {

        if (preStart > preEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        TreeNode* root = new TreeNode(preorder[preStart]);

        int nextNode = preorder[preStart + 1];
        int j = mpp[nextNode];
        int num = j - postStart + 1;

        root->left = solve(preorder, preStart + 1, preStart + num,
                           postorder, postStart, mpp);

        root->right = solve(preorder, preStart + num + 1, preEnd,
                            postorder, j + 1, mpp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < postorder.size(); i++) {
            mpp[postorder[i]] = i;
        }

        return solve(preorder, 0, preorder.size() - 1, postorder, 0, mpp);
    }
};
