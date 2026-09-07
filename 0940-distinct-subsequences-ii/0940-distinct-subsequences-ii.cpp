class Solution {
public:
    const int mod = 1e9+7;
    int distinctSubseqII(string s) {
        // baaba
        // a -> 1
        // a, ba, b -> 1 + 1 + 1 = 3
        // -> 3 + 3 + 1 - 1 = 6
        // -> 6 + 6 + 1 - 1 - 3 = 9
        // -> 9 + 9 + 1 - 1 - 1 = 17
        // -> 2*no of subsequences of the string from i+1 to n + 1(own) - if the character already present at jth position (i+1 to n) then substract the no of subsequence starting with jth charcter (1 + no of sub in string from j+1 to n)
        // int sub = 0;
        // for(auto &idx: mpp[s[i]]){
        //    if(idx > i) sub += 1 + (idx+1 < n? dp[idx+1]: 0);
        // }
        // 2*sub[i+1] + 1 - (1 + sub)
        int n = s.size();
        unordered_map<char, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[s[i]].push_back(i);
        }
        vector<int> dp(n, 1);
        for(int i = n-2;i>=0;i--){
            int sub = 0;
            // bool fg = false;
            for(auto &idx: mpp[s[i]]){
                if(idx > i){
                    sub = (1 + (idx+1 < n? dp[idx+1]: 0))%mod;
                    break;
                    // fg = true;
                }
            }
            dp[i] = (2LL * dp[i+1] + 1 - sub + mod) % mod;
            cout << i << " " << sub << " " << dp[i] << endl;
        }
        return dp[0];
    }
};