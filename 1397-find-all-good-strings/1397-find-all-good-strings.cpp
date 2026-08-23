class Solution {
public:
    vector<int> lps;
    int dp[505][2][55];
    const int mod = 1e9+7;
    void constructLps(string &pat) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < pat.length()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Changed return type to bool
    bool search(string &pat, string &txt) {
        int n = txt.length();
        int m = pat.length();
        
        // Edge case: if pattern is empty, technically it's always found
        if (m == 0) return true;
        constructLps(pat);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;

                // If the entire pattern is matched, return true immediately
                if (j == m) {
                    return true; 
                }
            }
            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        
        // If the loop finishes and no match was found, return false
        return false; 
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
            int next = match_len;
            while(next > 0 && evil[next] != dig){
                next = lps[next-1];
            }
            if(evil[next] == dig) next++;
            res = (res +solve(s, evil, idx+1, (tight && s[idx] == dig), next))%mod;
        }
        return dp[idx][tight][match_len] = res%mod;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        lps.resize(evil.size());
        constructLps(evil);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(s1, evil, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(s2, evil, 0, 1, 0);
        int add = 1 - search(evil, s1);
        return (ans2 - ans1 + add+mod)%mod;
    }
};