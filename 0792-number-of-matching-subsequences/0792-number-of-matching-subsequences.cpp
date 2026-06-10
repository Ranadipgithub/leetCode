class Solution {
public:
    bool isSub(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        
        unordered_map<string, int> mpp;
        for(string &word: words) mpp[word]++;
        for(auto it: mpp){
            if(isSub(s, it.first)) cnt+=mpp[it.first];
        }
        return cnt;
    }
};