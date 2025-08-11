class Solution {
public:
    const int MOD = 1e9+7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        string s = "";
        while(n != 1){
            int rem = n%2;
            s += rem + '0';
            n = n/2;
        }
        if(n == 1) s += '1';
        reverse(s.begin(), s.end());
        vector<int> pdt;
        int size = s.size();
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '1'){
                int idx = size - i -1;
                pdt.push_back(1<<idx);
            }
        }
        
        int n1 = pdt.size();
        vector<long long> pre(n1);
        pre[0] = pdt[0];
        for(int i = 1; i < pdt.size(); i++){
            pre[i] = (pdt[i] * pre[i-1]) % MOD;
        }
        
        vector<int> res;
        for(auto& it: queries){
            int left = it[0];
            int right = it[1];
            if(left == 0) {
                res.push_back((int)pre[right]);
            } else {
                long long left_inv = modInverse(pre[left-1]);
                long long ans = (pre[right] * left_inv) % MOD;
                res.push_back((int)ans);
            }
        }
        return res;
    }
};