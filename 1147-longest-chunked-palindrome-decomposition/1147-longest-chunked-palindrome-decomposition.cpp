class Solution {
public:
    void findLps(vector<int>&lps, string &s, int i, int j){
        int pre = 0, suff = 1;
        while(suff <= j-i){
            if(s[i+pre] == s[i+suff]){
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                } 
                else pre = lps[pre-1];
            }
        }
    }
    int longestDecomposition(string text) {
        // antaprezatepzapreanta
        // 000100001000010001234 
        int n = text.size();
        int i = 0, j = n-1;
        int cnt = 0;
        while(i <= j){
            vector<int> lps(j-i+1, 0);
            findLps(lps, text, i, j);
            int len = lps[lps.size()-1];
            if(len == 0){
                cnt++;
                break;
            }
            while(len > 0 && lps[len-1] > 0){
                len = lps[len-1];
            }
            cnt+=2;
            i+=len;
            j-=len;
        }
        return cnt;
    }
};