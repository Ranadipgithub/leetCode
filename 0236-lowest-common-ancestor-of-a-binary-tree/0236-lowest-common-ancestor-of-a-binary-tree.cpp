/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if (getPath(root->left,  target, path) ||
            getPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        getPath(root, p, pathP);
        getPath(root, q, pathQ);

        TreeNode* lca = nullptr;
        int n = min(pathP.size(), pathQ.size());
        for (int i = 0; i < n; i++) {
            if (pathP[i] == pathQ[i]) {
                lca = pathP[i];
            } else {
                break;
            }
        }
        return lca;
    }
};
