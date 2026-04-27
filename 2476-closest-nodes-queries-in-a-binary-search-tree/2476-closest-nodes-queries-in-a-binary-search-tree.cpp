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
    void inorder(TreeNode *root, vector<int>&sorted){
        if(root == NULL) return;
        if(root->left) inorder(root->left, sorted);
        sorted.push_back(root->val);
        if(root->right) inorder(root->right, sorted);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sorted;
        inorder(root, sorted);
        vector<vector<int>> res;
        for(int val: queries){
            int ceil = -1;
            auto it1 = lower_bound(sorted.begin(), sorted.end(), val);
            if(it1 == sorted.end()) ceil = -1;
            else ceil = *it1;
            int floor = -1;
            auto it2 = upper_bound(sorted.begin(), sorted.end(), val);
            if(it2 == sorted.begin()) floor = -1;
            else floor = *(--it2);
            res.push_back({floor, ceil});
        }
        return res;
    }
};