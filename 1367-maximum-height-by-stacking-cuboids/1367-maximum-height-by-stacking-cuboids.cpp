class Solution {
private:
    bool canStack(const vector<int>& base, const vector<int>& top) {
        return base[0] <= top[0] &&
               base[1] <= top[1] &&
               base[2] <= top[2];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &arr: cuboids){
            sort(arr.begin(), arr.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; 
            for (int j = 0; j < i; j++) {
                if (canStack(cuboids[j], cuboids[i])) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }
        return maxHeight;
    }  
};