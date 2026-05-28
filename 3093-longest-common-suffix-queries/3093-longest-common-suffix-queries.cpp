class Solution {
public:
    struct TrieNode {
        TrieNode *children[26];
        int idx, len;
        TrieNode(){
            idx = 0;
            len = INT_MAX;
            for(int i = 0;i<26;i++) children[i] = NULL;
        }
        ~TrieNode(){
            for(int i = 0;i<26;i++){
                delete children[i];
            }
        }
    };
    TrieNode *getNode(){
        return new TrieNode();
    }

    void insert(string &word, TrieNode *root, int index){
        TrieNode *ptr = root;
        int newLen = word.size();
        for(int i = 0;i<newLen;i++){
            if(ptr->children[word[i]-'a'] == NULL){
                ptr->children[word[i]-'a'] = getNode();
            }
            if(newLen < ptr->len){
                ptr->len = newLen;
                ptr->idx = index;
            } else if(newLen == ptr->len && index < ptr->idx){
                ptr->idx = index;
            }
            ptr = ptr->children[word[i]-'a'];
        }
        if(newLen < ptr->len){
            ptr->len = newLen;
            ptr->idx = index;
        } else if(newLen == ptr->len && index < ptr->idx){
            ptr->idx = index;
        }
    }
    int Query(string &word, TrieNode *root){
        TrieNode *ptr = root;
        for(int i = 0;i<word.size();i++){
            if(ptr->children[word[i]-'a'] == NULL) return ptr->idx;
            ptr = ptr->children[word[i]-'a'];
        }
        return ptr->idx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode *root = getNode();
        int n = wordsContainer.size();
        for(int i = 0;i<n;i++){
            string temp = wordsContainer[i];
            reverse(temp.begin(), temp.end());
            insert(temp, root, i);
        }
        vector<int> res;
        for(string &s: wordsQuery){
            reverse(s.begin(), s.end());
            int idx = Query(s, root);
            res.push_back(idx);
        }
        delete root;
        return res;
    }
};