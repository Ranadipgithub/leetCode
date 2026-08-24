class Solution {
public:
    vector<int> lps;
    void findLps(string &s){
        int pre = 0, suff = 1;
        while(suff < s.size()){
            if(s[pre] == s[suff]){
                lps[suff] = pre +1;
                pre++;
                suff++;
            } else {
                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                } else {
                    pre = lps[pre-1];
                }
            }
        }
    }
    int search(string &pat, string &txt){
        int n = pat.size();
        // vector<int> lps(n, 0);
        lps.assign(n, 0);
        findLps(pat);
        int first = 0, second = 0;
        while(first < txt.size()){
            if(txt[first] == pat[second]){
                first++;
                second++;
                if(second == pat.size()){
                    return first-pat.size();
                }
            } else {
                // if(second == 0) first++;
                // else second = lps[second-1];
                return -1;
            }
        }
        return -1;
    }
    int minimumTimeToInitialState(string word, int k) {
        // abaca k = 2
        // aca??
        // a????
        // abcabcabc k = 1
        // bcabcabc?
        // cabcabc??
        // abcabc???
        // a b c a b c a b c
        // 0 0 0 1 2 3 1 2 3
        // 
        
        int n = word.size();
        if(k == 1){
            lps.assign(n, 0);
            findLps(word);
            return n - lps[n - 1];
        }
        int cnt = 0;
        for(int i = k;i<n;i+=k){
            string temp = word.substr(i);
            int idx = search(temp, word);
            cnt++;
            if(idx == 0) return cnt;
        }
        return cnt+1;
    }
};