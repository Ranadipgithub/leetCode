class Solution {
public:
    struct TrieNode {
        TrieNode *children[26];
        int cnt;
    };
    TrieNode *getNode(){
        TrieNode *newNode = new TrieNode();
        newNode->cnt = 0;
        for(int i = 0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(string &word, TrieNode *root){
        TrieNode *ptr = root;
        for(int i = 0;i<word.size();i++){
            if(ptr->children[word[i]-'a'] == NULL){
                ptr->children[word[i]-'a'] = getNode();
            }
            ptr = ptr->children[word[i]-'a'];
            ptr->cnt++;
        }
    }
    int Query(string &word, TrieNode *root){
        TrieNode *ptr = root;
        int cnt = 0;
        for(int i = 0;i<word.size();i++){
            ptr = ptr->children[word[i]-'a'];
            cnt += ptr->cnt;
        }
        return cnt;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *root = getNode();
        for(string word: words){
            insert(word, root);
        }
        vector<int> res;
        for(int i = 0;i<words.size();i++){
            int temp = Query(words[i], root);
            res.push_back(temp);
        }
        return res;
    }
};