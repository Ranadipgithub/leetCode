class Solution {
public:
    const int mod = 1e9+7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int size = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> mpp;
        for(auto &q: queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if(k >= size){
                for(int i = l; i <= r; i += k){
                    nums[i] = (1LL * nums[i] * v) % mod; 
                }
            } else {
                mpp[k].push_back(q);
            }
        }

        for(auto &it: mpp){
            int k = it.first;
            vector<long long> diff(n, 1); 
            for(auto &q: it.second){
                int l = q[0], r = q[1], v = q[3]; 
                diff[l] = (diff[l] * v) % mod;
                int steps = (r - l) / k;
                int next = ((steps + 1) * k) + l;
                if(next < n) diff[next] = (diff[next] * modInverse(v)) % mod;
            }

            for(int i = k; i < n; i++){ 
                diff[i] = (diff[i] * diff[i-k]) % mod;
            }
            for(int i = 0; i < n; i++){
                nums[i] = (1LL * nums[i] * diff[i]) % mod; 
            }
        }

        int xorr = 0;
        for(int i = 0; i < n; i++){
            xorr ^= nums[i];
        }
        return xorr;
    }
};