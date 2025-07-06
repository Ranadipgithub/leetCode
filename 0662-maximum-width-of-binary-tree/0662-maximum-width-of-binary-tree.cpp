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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxW = 0;
        while(!q.empty()){
            int size = q.size();
            long long l = q.front().second;
            long long r = q.back().second;
            maxW = max(maxW, r-l+1);
            while(size--){
                auto it = q.front();
                q.pop();
                TreeNode *node = it.first;
                int idx = it.second;
                if(node->left) q.push({node->left, (long long)2*idx+1});
                if(node->right) q.push({node->right, (long long)2*idx+2});
            }
        }
        return (int)maxW;
    }
};