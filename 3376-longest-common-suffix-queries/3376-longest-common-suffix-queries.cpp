class Solution {
public:
    struct TrieNode {
        int children[26];
        int idx;
        int len;

        TrieNode() : idx(0), len(INT_MAX) {
            for(int i = 0; i < 26; i++) {
                children[i] = 0;
            }
        }
    };

    vector<TrieNode> trie;

    int newNode() {
        trie.push_back(TrieNode());
        return trie.size() - 1; 
    }


    void insert(string &word, int rootIdx, int index){ 
        int ptr = rootIdx;
        int newlen = word.size();

        for(int i = 0; i < word.size(); i++){
            int charIdx = word[i] - 'a';
            
            if (trie[ptr].children[charIdx] == 0) {
                int nextNodeIdx = newNode();
                trie[ptr].children[charIdx] = nextNodeIdx;
            } 
            
            if (newlen < trie[ptr].len) {
                trie[ptr].idx = index;
                trie[ptr].len = newlen; 
            } else if (newlen == trie[ptr].len) {
                if (index < trie[ptr].idx) { 
                    trie[ptr].idx = index;
                }
            }
            
            ptr = trie[ptr].children[charIdx];
        }
        
        if (newlen < trie[ptr].len) {
            trie[ptr].idx = index;
            trie[ptr].len = newlen;
        } else if (newlen == trie[ptr].len) {
            if (index < trie[ptr].idx) {
                trie[ptr].idx = index;
            }
        }
    }

    int Query(string &s, int rootIdx){
        int ptr = rootIdx;
        for(int i = 0; i < s.size(); i++){
            int charIdx = s[i] - 'a';
            if (trie[ptr].children[charIdx] == 0) { 
                return trie[ptr].idx; 
            } 
            ptr = trie[ptr].children[charIdx]; 
        }
        return trie[ptr].idx; 
    }


    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        
        trie.clear(); 
        trie.push_back(TrieNode()); 
        int root = newNode();
        
        int idx = 0;
        int mini = wordsContainer[0].size();
        for(int i = 1; i < n; i++){
            if(wordsContainer[i].size() < mini){
                mini = wordsContainer[i].size();
                idx = i;
            }
        }
        
        trie[root].idx = idx;
        trie[root].len = mini;


        for(int i = 0; i < n; i++){
            string temp = wordsContainer[i];
            reverse(temp.begin(), temp.end());
            insert(temp, root, i);
        }

        vector<int> res;
        for(string s: wordsQuery){
            reverse(s.begin(), s.end());
            int ansIdx = Query(s, root); 
            res.push_back(ansIdx);
        }

        return res;
    }
};