class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int prev = 0;
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        for(int k = 0; k <= n + m - 2; k++){
            vector<int> temp = mpp[k];
            if(prev == 1){
                for(int x = 0; x < temp.size(); x++){
                    res.push_back(temp[x]);
                }
            } else {
                reverse(temp.begin(), temp.end());
                for(int x = 0; x < temp.size(); x++){
                    res.push_back(temp[x]);
                }
            }
            prev = 1 - prev;
        }

        return res;
    }
};
