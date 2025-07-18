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
    map<int, vector<TreeNode *>> mpp;
    vector<TreeNode *> solve(int n){
        if(n == 1){
            return {new TreeNode(0)};
        }

        if(mpp.find(n) != mpp.end()) return mpp[n];

        vector<TreeNode *> result;

        for(int leftCount = 1; leftCount < n; leftCount += 2){
            int rightCount = n - 1 - leftCount;
            vector<TreeNode *> left = solve(leftCount);
            vector<TreeNode *> right = solve(rightCount);

            for(TreeNode *leftRoot : left){
                for(TreeNode *rightRoot : right){
                    TreeNode *root = new TreeNode(0);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }
        return mpp[n] = result;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        return solve(n);
    }
};