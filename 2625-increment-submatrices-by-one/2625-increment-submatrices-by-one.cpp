class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for(auto it: queries){
            int x1 = it[0], y1 = it[1];
            int x2 = it[2], y2 = it[3];

            for(int i = x1;i<=x2;i++){
                diff[i][y1] += 1;
                if(y2+1 < n){
                    diff[i][y2+1] -=1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j-1];
            }
        }

        return diff;
    }
};