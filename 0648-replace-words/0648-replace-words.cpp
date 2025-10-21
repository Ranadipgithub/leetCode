class Solution {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode *children[26];
        string word;
    };

    TrieNode *getNode() {
        TrieNode *newNode = new TrieNode();
        newNode->isEndOfWord = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(string &s, TrieNode *root) {
        TrieNode *ptr = root;
        for (int i = 0; i < s.size(); i++) {
            if (ptr->children[s[i] - 'a'] == NULL) {
                ptr->children[s[i] - 'a'] = getNode();
            }
            ptr = ptr->children[s[i] - 'a'];
        }
        ptr->isEndOfWord = true;
        ptr->word = s;
    }

    string Query(string &s, TrieNode *root) {
        TrieNode *ptr = root;
        for (int i = 0; i < s.size(); i++) {
            if (ptr->children[s[i] - 'a'] == NULL) {
                return "";
            }
            ptr = ptr->children[s[i] - 'a'];
            if (ptr->isEndOfWord == true) {
                return ptr->word;
            }
        }
        return "";
    }

    string replaceWords(vector<string>& dictionary, string s) {
        TrieNode *root = getNode();
        for (string &str : dictionary) {
            insert(str, root);
        }

        int i = 0;
        vector<string> res;
        int n = s.size();
        for (int j = 0; j < n; j++) {
            if (s[j] == ' ') {
                string temp = s.substr(i, j - i);
                res.push_back(temp);
                i = j + 1;
            }
        }
        res.push_back(s.substr(i));

        string ans = "";
        for (int i = 0; i < res.size(); i++) {
            string temp = Query(res[i], root);
            if (temp == "") {
                ans += res[i];
            } else {
                ans += temp;
            }
            if (i != res.size() - 1) ans += " ";
        }

        return ans;
    }
};