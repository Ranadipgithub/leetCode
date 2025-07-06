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
    int maxi = INT_MIN;
    int dfs(TreeNode *root, int target){
        if(root == NULL) return 0;
        int lh = dfs(root->left, target);
        int rh = dfs(root->right, target);

        if(root->val == target){
            maxi = max(lh, rh);
            return -1;
        } else if(lh >= 0 && rh >= 0){
            return 1 + max(lh, rh);
        } else{
            int dist = abs(lh) + abs(rh);
            maxi = max(maxi, dist);
            return min(lh, rh)-1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxi;
    }
};