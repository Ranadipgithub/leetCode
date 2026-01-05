class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        long long sum = 0, maxi = LLONG_MIN, cnt = 0, mini = LLONG_MAX;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] <= 0){
                    cnt++;
                    maxi = max(maxi, 1LL*matrix[i][j]);
                }
                mini = min(mini, 1LL*abs(matrix[i][j]));
                sum += (long long)abs(matrix[i][j]);
            }
        }
        cout << maxi << sum;
        return cnt%2 == 0? sum: sum-2*mini;
    }
};