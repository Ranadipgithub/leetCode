class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(int i, int j, vector<vector<int>>& ocean, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        ocean[i][j ] = 1;
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            if(newi < 0 || newi >=n || newj < 0 || newj >=m || ocean[newi][newj] == 1 || heights[i][j] > heights[newi][newj]){
                continue;
            }

            dfs(newi, newj, ocean, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for(int i = 0;i<m;i++){
            dfs(0, i, pacific, heights);
        }

        for(int i = 0;i<n;i++){
            dfs(i, 0, pacific, heights);
        }

        for(int i = 0;i<n;i++){
            dfs(i, m-1, atlantic, heights);
        }

        for(int i = 0;i<m;i++){
            dfs(n-1, i, atlantic, heights);
        }

        vector<vector<int>> res;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};