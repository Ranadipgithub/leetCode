class Solution {
public:
    struct TrieNode {
        TrieNode *left;
        TrieNode *right;
        TrieNode() : left(nullptr), right(nullptr) {}
    };

    void insert(int num, TrieNode *root) {
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (!root->left) root->left = new TrieNode();
                root = root->left;
            } else {
                if (!root->right) root->right = new TrieNode();
                root = root->right;
            }
        }
    }

    int findMaxXor(int num, TrieNode *root) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (root->right) {
                    res += (1 << i);
                    root = root->right;
                } else {
                    root = root->left;
                }
            } else {
                if (root->left) {
                    res += (1 << i);
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
        }
        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        for (int num : nums) {
            insert(num, root);
        }
        int maxi = 0;
        for (int num : nums) {
            maxi = max(maxi, findMaxXor(num, root));
        }
        return maxi;
    }
};