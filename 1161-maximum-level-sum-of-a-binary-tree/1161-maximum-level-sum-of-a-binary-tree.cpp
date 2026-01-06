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
    int maxLevelSum(TreeNode* root) {
        TreeNode *temp = root;
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int maxi = INT_MIN, level = 1, ans = -1;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode *temp1 = q.front();
                q.pop();
                sum += temp1->val;
                if(temp1->left) q.push(temp1->left);
                if(temp1->right) q.push(temp1->right);
            }
            if(sum > maxi){
                maxi = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};