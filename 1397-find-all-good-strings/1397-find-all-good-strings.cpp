class Solution {
public:
    vector<int> lps;
    int dp[505][2][55];
    int trans[55][26];
    const int mod = 1e9+7;
    void constructLps(string &s){
        int n = s.size();
        int pre = 0, suff = 1;
        while(suff < n){
            if(s[pre] == s[suff]){
                lps[suff] = pre+1;
                pre++;
                suff++;
            } else {
                if(pre == 0){
                    suff++;
                } else {
                    pre = lps[pre-1];
                }
            }
        }
    }
    bool search(string &pat, string &txt) {
        int n = txt.size();
        int first = 0, second = 0;
        int m = pat.size();
        vector<int> res;
        while(first < n){
            if(txt[first] == pat[second]){
                first++;
                second++;
                if(second == m){
                    return true;
                }
            } else {
                if(second == 0) first++;
                else {
                    second = lps[second-1];
                }
            }
        }
        return false;
    }
    void buildTransitions(string &evil){
        int m = evil.size();
        for(int i = 0;i<m;i++){
            for(char c = 'a';c<='z';c++){
                int next = i;
                while(next > 0 && evil[next] != c){
                    next = lps[next-1];
                }
                if(evil[next] == c){
                    next++;
                }
                trans[i][c-'a'] = next;
            }
        }
    }

    int solve(string &s, string &evil, int idx, bool tight, int match_len){
        if(match_len == evil.size()) return 0;
        if(idx == s.size()){
            return 1;
        }
        int lb = 'a';
        int ub = (tight == 1)? s[idx]: 'z';
        int res = 0;
        if(dp[idx][tight][match_len] != -1) return dp[idx][tight][match_len];
        for(char dig = lb;dig <= ub;dig++){
            // int next = match_len;
            // while(next > 0 && evil[next] != dig){
            //     next = lps[next-1];
            // }
            // if(evil[next] == dig) next++;
            int next = trans[match_len][dig-'a'];
            res = (res +solve(s, evil, idx+1, (tight && s[idx] == dig), next))%mod;
        }
        return dp[idx][tight][match_len] = res%mod;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        lps.resize(evil.size());
        constructLps(evil);
        buildTransitions(evil);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(s1, evil, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(s2, evil, 0, 1, 0);
        int add = 1 - search(evil, s1);
        return (ans2 - ans1 + add+mod)%mod;
    }
};