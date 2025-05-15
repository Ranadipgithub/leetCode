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
    TreeNode* solve(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[start]);

        int rightSubtreeStart = end + 1;
        for (int i = start + 1; i <= end; i++) {
            if (preorder[i] > preorder[start]) {
                rightSubtreeStart = i;
                break;
            }
        }

        root->left = solve(preorder, start + 1, rightSubtreeStart - 1);
        root->right = solve(preorder, rightSubtreeStart, end);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size() - 1);
    }
};
