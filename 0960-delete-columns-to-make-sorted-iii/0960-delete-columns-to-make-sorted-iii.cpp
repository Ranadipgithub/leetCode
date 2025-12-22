class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> dp(m, 1);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<i;j++){
                bool fg = true;
                for(int k = 0;k<n;k++){
                    if(strs[k][i] < strs[k][j]){
                        fg = false;
                    }
                }
                if(fg) dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        int lis = *max_element(dp.begin(), dp.end());
        return m - lis;
    }
};