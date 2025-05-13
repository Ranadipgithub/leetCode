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
    void find(TreeNode *root, int pos, int &l, int &r) {
        if (!root) return;
        l = min(pos, l);
        r = max(pos, r);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<pair<int, int>>> positives(r + 1);
        vector<vector<pair<int, int>>> negatives(abs(l) + 1);

        queue<TreeNode*> q;
        queue<int> index, level;
        q.push(root);
        index.push(0);
        level.push(0);

        while (!q.empty()) {
            TreeNode* temp = q.front(); q.pop();
            int pos = index.front(); index.pop();
            int row = level.front(); level.pop();

            if (pos >= 0) positives[pos].emplace_back(row, temp->val);
            else negatives[abs(pos)].emplace_back(row, temp->val);

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
                level.push(row + 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
                level.push(row + 1);
            }
        }

        vector<vector<int>> res;
        for (int i = negatives.size() - 1; i >= 1; i--) {
            sort(negatives[i].begin(), negatives[i].end());
            vector<int> col;
            for (auto& p : negatives[i]) col.push_back(p.second);
            res.push_back(col);
        }

        for (int i = 0; i < positives.size(); i++) {
            sort(positives[i].begin(), positives[i].end());
            vector<int> col;
            for (auto& p : positives[i]) col.push_back(p.second);
            res.push_back(col);
        }

        return res;
    }
};
