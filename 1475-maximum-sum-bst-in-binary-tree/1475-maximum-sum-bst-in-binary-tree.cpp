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
    class Box{
        public:
            bool bst;
            int sum;
            int mini;
            int maxi;
        Box(){
            bst = 1;
            sum = 0;
            mini = INT_MAX;
            maxi = INT_MIN;
        }
    };

    Box *find(TreeNode *root, int &totalsum){
        if(!root){
            return new Box();
        }
        Box *lefthead = find(root->left, totalsum);
        Box *righthead = find(root->right, totalsum);
        
        if(lefthead->bst && righthead->bst && lefthead->maxi < root->val && righthead->mini > root->val){
            Box *head = new Box();
            head->sum = root->val + lefthead->sum + righthead->sum;
            head->mini = min(lefthead->mini, root->val); 
            head->maxi = max(righthead->maxi, root->val); 
            totalsum = max(totalsum, head->sum);
            return head;
        } else{
            Box *head = new Box(); 
            head->bst = 0;
            return head;
        }
    }

    int maxSumBST(TreeNode* root) {
        int totalsum = 0;
        find(root, totalsum);
        return totalsum;
    }
};