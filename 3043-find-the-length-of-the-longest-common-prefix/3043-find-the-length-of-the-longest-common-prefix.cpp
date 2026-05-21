class Solution {
public:
    struct TrieNode{
        TrieNode *children[10];
    };
    TrieNode *getNode(){
        TrieNode *newNode = new TrieNode();
        for(int i = 0;i<10;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(int num, TrieNode *root){
        string s = to_string(num);
        int n = s.size();
        TrieNode *ptr = root;
        for(int i = 0;i<n;i++){
            if(ptr->children[s[i]-'0'] == NULL){
                ptr->children[s[i] - '0'] = getNode();
            }
            ptr = ptr->children[s[i] - '0'];
        }
    }
    int Query(int num, TrieNode *root){
        string s = to_string(num);
        int len = 0;
        for(int i = 0;i<s.size();i++){
            if(root->children[s[i]-'0'] == NULL){
                return len;
            }
            len++;
            root = root->children[s[i]-'0'];
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        TrieNode *root = getNode();
        for(int num: arr1){
            insert(num, root);
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            int temp = Query(arr2[i], root);
            ans = max(ans, temp);
        }
        return ans;
    }
};