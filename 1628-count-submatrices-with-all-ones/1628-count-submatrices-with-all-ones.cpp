class Solution {
public:
    int solve(vector<int>& arr, int val){
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = (arr[0] >= val) ? 1 : 0;    
        for (int i = 1; i < n; i++){
            if (arr[i] >= val) dp[i] = dp[i-1] + 1;  
            else dp[i] = 0;
        }
        int cnt = 0;
        for (int x : dp) cnt += x;
        return cnt;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        vector<vector<int>> presum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++){
            presum[0][j] = mat[0][j];
            for (int i = 1; i < n; i++){
                presum[i][j] = (mat[i][j] ? presum[i-1][j] + 1 : 0); 
            }
        }

        for (int i = 0; i < n; i++){
            cnt += solve(presum[i], 1);
        }

        for (int i = 1; i < n; i++){
            for (int h = 2; h <= i + 1; h++){
                cnt += solve(presum[i], h);
            }
        }
        return cnt;
    }
};