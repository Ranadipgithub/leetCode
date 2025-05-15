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
    TreeNode *prev = nullptr;
    int cnt = 1, maxcnt = 0;

    void inorder(TreeNode *root, vector<int>& res) {
        if (!root) return;

        inorder(root->left, res);

        if (prev) {
            if (root->val == prev->val) {
                cnt++;
            } else {
                cnt = 1;
            }
        }

        if (cnt > maxcnt) {
            maxcnt = cnt;
            res.clear();
            res.push_back(root->val);
        } else if (cnt == maxcnt) {
            res.push_back(root->val);
        }

        prev = root;

        inorder(root->right, res);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
