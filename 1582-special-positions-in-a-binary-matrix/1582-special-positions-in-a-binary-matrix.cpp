class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<int> oneRow(n, 0), oneCol(m, 0);
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1) cnt++;
            }
            oneRow[i] = cnt;
        }

        for(int j = 0;j<m;j++){
            int cnt = 0;
            for(int i = 0;i<n;i++){
                if(mat[i][j] == 1) cnt++;
            }
            oneCol[j] = cnt;
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1){
                    if(oneRow[i] == 1 && oneCol[j] == 1) cnt++;
                }
            }
        }
        return cnt;
    }
};