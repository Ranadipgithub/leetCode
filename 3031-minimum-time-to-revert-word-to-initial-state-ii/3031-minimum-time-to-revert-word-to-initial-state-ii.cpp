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
        lps.assign(n, 0);
        findLps(word);
        if(k == 1){
            return n - lps[n - 1];
        }
        int cnt = 1;
        // baba k = 3
        // 0012 only 2 length lps possible
        vector<int> isValid(n+1, false);
        int len = lps[n-1];
        while(len>0){
            isValid[len] = true;
            len = lps[len-1];
        }
        for(int i = k;i<n;i+=k){
            if(isValid[n-i]) return cnt;
            cnt++;
        }
        return cnt;
    }
};