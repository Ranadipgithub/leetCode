class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int &maxi, int &maxj) {
        int n = land.size();
        int m = land[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || land[i][j] != 1)
            return;

        land[i][j] = -1;
        maxi = max(maxi, i);
        maxj = max(maxj, j);

        dfs(land, i + 1, j, maxi, maxj); 
        dfs(land, i, j + 1, maxi, maxj);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> res;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    int maxi = i, maxj = j;
                    dfs(land, i, j, maxi, maxj);
                    res.push_back({i, j, maxi, maxj});
                }
            }
        }
        return res;
    }
};
