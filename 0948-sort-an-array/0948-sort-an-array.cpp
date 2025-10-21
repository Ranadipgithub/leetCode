class Solution {
public:
    struct TrieNode {
        TrieNode *left;
        TrieNode *right;
        bool isEnd;
        int value;
        int count;
    };

    TrieNode *getNode() {
        TrieNode *newNode = new TrieNode();
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->isEnd = false;
        newNode->value = 0;
        newNode->count = 0;
        return newNode;
    }

    void insert(int num, TrieNode *root) {
        unsigned int n = static_cast<unsigned int>(num) ^ 0x80000000;

        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (!root->left) root->left = getNode();
                root = root->left;
            } else {
                if (!root->right) root->right = getNode();
                root = root->right;
            }
        }
        root->isEnd = true;
        root->value = num;
        root->count += 1;
    }

    void dfs(TrieNode* node, vector<int>& result) {
        if (!node) return;
        if (node->isEnd) {
            for (int i = 0; i < node->count; i++)
                result.push_back(node->value);
        }
        dfs(node->left, result);
        dfs(node->right, result);
    }

    vector<int> getSorted(TrieNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    vector<int> sortArray(vector<int>& nums) {
        TrieNode *root = getNode();
        for (int num : nums) {
            insert(num, root);
        }
        return getSorted(root);
    }
};