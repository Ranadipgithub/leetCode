class Solution {
public:
    int dp[4005];
    int solve(string &s, int idx, unordered_map<int, vector<int>>&adj){
        if(idx == s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ops = 1;
        for(auto it: adj[idx]){
            ops =  max(ops, 1 + solve(s, it, adj));
        }
        return dp[idx] = ops;
    }
    void findLps(vector<int>&lps, string &s){
        int pre = 0, suff = 1;
        while(suff < s.size()){
            if(s[pre] == s[suff]){
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if(pre == 0) suff++;
                else {
                    pre = lps[pre-1];
                }
            }
        }
    }
    int deleteString(string s) {
        int n = s.size();
        unordered_map<int, vector<int>> adj;
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<n;i++){
            vector<int> lps(n-i, 0);
            string temp = s.substr(i);
            findLps(lps, temp);
            // for(auto it: lps) cout << it << " ";
            // cout << endl;
            for(int j = 1;j<lps.size();j+=2){
                if(lps[j] * 2 == j+1){
                    adj[i].push_back(i+(j+1)/2);
                }
            }
        }
        for(auto it: adj){
            cout << it.first << " ";
            for(auto lt: it.second) cout << lt << " ";
            cout << endl;
        }
        return solve(s, 0, adj);
    }
};