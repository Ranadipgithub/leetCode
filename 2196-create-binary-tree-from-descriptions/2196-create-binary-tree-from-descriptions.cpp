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
    TreeNode* solve(int val, unordered_map<int, vector<pair<int,int>>> &adj) {
        TreeNode* node = new TreeNode(val);
        for (auto &child:adj[val]) {
            int childVal = child.first;
            int isLeft = child.second;
            if (isLeft == 1) {
                node->left = solve(childVal, adj);
            } else {
                node->right = solve(childVal, adj);
            }
        }
        return node;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st;
        for (auto &it:descriptions) {
            st.insert(it[0]);
            st.insert(it[1]);
        }
        for (auto &it:descriptions) {
            st.erase(it[1]);
        }
        int rootVal = *st.begin();
        unordered_map<int, vector<pair<int,int>>> adj;
        for (auto &it:descriptions) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        return solve(rootVal, adj);
    }
};