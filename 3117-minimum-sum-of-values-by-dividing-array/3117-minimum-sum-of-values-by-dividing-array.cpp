struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    // unordered_map<int, int> dp[10001][11];
    unordered_map<long long, int, custom_hash> dp;
    int solve(int i, int j, int curr, vector<int>&nums, vector<int>&vals){
        if(i == nums.size()){
            if(j == vals.size()) return 0;
            return 1e9;
        }
        if(j == vals.size()) return 1e9;
        long long key = (long long) curr << 18 | j << 14 | i;
        if(dp.count(key)) return dp[key];
        // if(dp[i][j].count(curr)) return dp[i][j][curr];
        if((curr & nums[i]) < vals[j]) return 1e9;
        int ans = solve(i+1, j, curr&nums[i], nums, vals);
        if((curr & nums[i]) == vals[j]){
            ans = min(ans, nums[i] + solve(i+1, j+1, (1<<17) -1, nums, vals));
        }
        return dp[key] = ans;
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int ans = solve(0, 0, (1 << 17) - 1, nums, andValues);
        return ans >= 1e9? -1: ans;
    }
};