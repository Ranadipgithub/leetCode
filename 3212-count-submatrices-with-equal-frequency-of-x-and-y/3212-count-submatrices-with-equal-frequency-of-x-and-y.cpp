class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> pre(n, vector<pair<int, int>>(m, {0, 0}));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (j > 0) pre[i][j] = pre[i][j-1];
                if(grid[i][j] == 'X') {
                    pre[i][j].first++;
                } else if(grid[i][j] == 'Y') { 
                    pre[i][j].second++;
                }
            }
        }

        vector<vector<pair<int, int>>> sum = pre;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum[i][j].first += sum[i-1][j].first;
                sum[i][j].second += sum[i-1][j].second;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(sum[i][j].first > 0 && sum[i][j].first == sum[i][j].second) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};