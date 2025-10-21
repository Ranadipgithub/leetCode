class Solution {
public:
    struct TrieNode {
        bool endOfWord;
        TrieNode *children[26];
        string word;
    };

    TrieNode *getNode(){
        TrieNode *newNode = new TrieNode();
        newNode->endOfWord = false;
        newNode->word = "";
        for(int i = 0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode *root, string &word){
        TrieNode *ptr = root;
        for(int i = 0;i<word.size();i++){
            if(ptr->children[word[i]-'a'] == NULL){
                ptr->children[word[i]-'a'] = getNode();
            }
            ptr = ptr->children[word[i] - 'a'];
        }
        ptr->endOfWord = true;
        ptr->word = word;
    }
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void findWords(int i, int j, vector<vector<char>>& board, vector<string> &res, TrieNode *root){
        int n = board.size(), m = board[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL) return;
        root = root->children[board[i][j] - 'a'];
        if(root->endOfWord){
            res.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            findWords(newi, newj, board, res, root);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        TrieNode *root = getNode();
        for(string word: words){
            insert(root, word);
        }
        vector<string> res;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                char ch = board[i][j];

                findWords(i, j, board, res, root);
            }
        }
        return res;
    }
};