class Solution {
public:
    struct TrieNode {
        TrieNode *children[26];
        int idx;
        int len;

        TrieNode() {
            idx = 0;
            len = INT_MAX;
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    TrieNode *getNode() {
        return new TrieNode();
    }

    void insert(string &word, TrieNode *root, int index) {
        TrieNode *ptr = root;
        int newlen = word.size();

        for (int i = 0; i < word.size(); i++) {
            if (ptr->children[word[i] - 'a'] == NULL) {
                ptr->children[word[i] - 'a'] = getNode();
            }

            if (newlen < ptr->len) {
                ptr->idx = index;
                ptr->len = newlen;
            } else if (newlen == ptr->len && index < ptr->idx) {
                ptr->idx = index;
            }

            ptr = ptr->children[word[i] - 'a'];
        }

        if (newlen < ptr->len) {
            ptr->idx = index;
            ptr->len = newlen;
        } else if (newlen == ptr->len && index < ptr->idx) {
            ptr->idx = index;
        }
    }

    int Query(string &s, TrieNode *root) {
        TrieNode *ptr = root;
        for (int i = 0; i < s.size(); i++) {
            if (ptr->children[s[i] - 'a'] == NULL) {
                return ptr->idx;
            }
            ptr = ptr->children[s[i] - 'a'];
        }
        return ptr->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        TrieNode *root = getNode();

        int idx = 0;
        int mini = wordsContainer[0].size();
        for (int i = 1; i < n; i++) {
            if (wordsContainer[i].size() < mini) {
                mini = wordsContainer[i].size();
                idx = i;
            }
        }
        root->idx = idx;
        root->len = mini;

        for (int i = 0; i < n; i++) {
            string temp = wordsContainer[i];
            reverse(temp.begin(), temp.end());
            insert(temp, root, i);
        }

        vector<int> res;
        for (string s : wordsQuery) {
            reverse(s.begin(), s.end());
            int ansIdx = Query(s, root);
            res.push_back(ansIdx);
        }

        delete root;
        return res;
    }
};