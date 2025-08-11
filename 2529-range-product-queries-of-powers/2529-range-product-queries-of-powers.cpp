class Solution {
public:
    const int MOD = 1e9+7;
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
        vector<int> res;
        for(auto it: queries){
            int left = it[0];
            int right = it[1];
            long long pdts = 1;
            for(int i = left;i<=right;i++){
                pdts = (pdts * pdt[i])%MOD;
            }
            res.push_back((int)pdts);
        }
        return res;
    }
};