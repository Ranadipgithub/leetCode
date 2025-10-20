class Trie {
public:
    struct TrieNode {
        TrieNode *children[26];
        bool fg;
    };

    TrieNode *getNode(){
        TrieNode *newNode = new TrieNode();
        newNode->fg = false;
        for(int i = 0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    TrieNode *root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode *ptr = root;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(ptr->children[idx] == NULL){
                ptr->children[idx] = getNode();
            }
            ptr = ptr->children[idx];
        }
        ptr->fg = true;
    }
    
    bool search(string word) {
        TrieNode *ptr = root;
        for(int i = 0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(ptr->children[idx] == NULL) return false;
            ptr = ptr->children[idx];
        }
        if(ptr != NULL && ptr->fg == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        int i = 0;
        for(;i<prefix.size();i++){
            int idx = prefix[i] - 'a';
            if(ptr->children[idx] == NULL) return false;
            ptr = ptr->children[idx];
        }
        if(i == prefix.length()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */