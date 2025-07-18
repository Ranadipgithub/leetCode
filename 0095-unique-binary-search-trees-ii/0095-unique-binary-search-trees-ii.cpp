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
    vector<int> result;
    map<pair<int, int>, vector<TreeNode *>> mpp;
    vector<TreeNode *> solve(int sidx, int eidx){
        if(sidx > eidx) return {nullptr};
        if(sidx == eidx) {
            TreeNode *newNode = new TreeNode(sidx);
            return {newNode};
        }

        if(mpp.find({sidx, eidx}) != mpp.end()) return mpp[{sidx, eidx}];

        vector<TreeNode *> result;
        for(int i = sidx;i<=eidx;i++){
            vector<TreeNode *> left = solve(sidx, i-1);
            vector<TreeNode *> right = solve(i+1, eidx);

            for(TreeNode *leftRoot : left){
                for(TreeNode *rightRoot: right){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }
        return mpp[{sidx, eidx}] = result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};