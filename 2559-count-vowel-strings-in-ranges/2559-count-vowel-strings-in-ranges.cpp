class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n, 0);
        pre[0] = isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1]);
        for(int i = 1;i<n;i++){
            string word = words[i];
            int num = isVowel(word[0]) && isVowel(word[word.size()-1]);
            pre[i] = pre[i-1] + num;
        }
        for(auto it: pre) cout << it << " ";
        vector<int> res;
        for(auto it: queries){
            int left = it[0], right = it[1];
            int num = left == 0? pre[right]: pre[right]-pre[left-1];
            res.push_back(num);
        }
        return res;
    }
};