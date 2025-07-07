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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    void populate(TreeNode* &root, vector<int> &ans, int &i){ 
        if(root == NULL) return;
        populate(root->left, ans, i);
        root->val = ans[i++];
        populate(root->right, ans, i);
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

        int n = res.size();
        vector<int> ans(n, 0);
        int sum = accumulate(res.begin(), res.end(), 0);
        int prev = 0;
        for(int i = 0;i<n;i++){
            ans[i] = sum - prev;
            prev += res[i];
        }

        int i = 0;
        populate(root, ans, i);
        return root;
    }
};
