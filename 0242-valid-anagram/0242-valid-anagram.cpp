class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;
        unordered_map<char, int> fq;
        for(auto ch: s){
            fq[ch]++;
        }
        for(int i = 0;i<n;i++){
            fq[t[i]]--;
            if(fq[t[i]] == 0) fq.erase(t[i]);
        }
        return fq.size() == 0;
    }
};