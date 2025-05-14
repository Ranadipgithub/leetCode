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
    unordered_map<TreeNode* , TreeNode*> parent;
    void inOrder(TreeNode *root){
        if(root == nullptr) return;
        if(root->left != nullptr) parent[root->left] = root;
        inOrder(root->left);
        if(root->right != nullptr) parent[root->right] = root;
        inOrder(root->right);
    }
    void bfs(TreeNode *target, int k , vector<int>&res){
        queue<TreeNode *>q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();
            if(k == 0) break;
            while(n--){
                TreeNode *curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            res.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        inOrder(root);
        bfs( target, k, res);
        return res;

    }
};