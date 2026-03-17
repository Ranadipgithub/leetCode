class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                temp[i][j] = matrix[i][j] == 1 && i>0? temp[i-1][j] + 1: matrix[i][j];
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            sort(temp[i].begin(), temp[i].end(), greater<int>());
            for(int j = 0;j<m;j++){
                if(temp[i][j] == 0) break;
                ans = max(ans, temp[i][j]*(j+1));
            }
        }
        return ans;
    }
};