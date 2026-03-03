class Solution {
public:
    vector<string> dp;
    string invert(string s){
        string res = "";
        for(char ch: s){
            if(ch == '1') res += '0';
            else res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string solve(int n){
        if(n == 1) return "0";
        if(dp[n] != "1") return dp[n];
        string temp = solve(n-1);
        return dp[n] = temp + '1' + invert(temp);
    }
    char findKthBit(int n, int k) {
        // 0
        // 011
        // 0111001
        // 011100110110001

        dp.resize(n+1, "1");
        string res = solve(n);
        return res[k-1];
    }
};