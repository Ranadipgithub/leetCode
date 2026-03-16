class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> post(n + 1, vector<int>(m + 2, 0));
        vector<vector<int>> pre(n + 1, vector<int>(m + 2, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                post[i][j] = grid[i-1][j-1] + post[i-1][j-1];
                pre[i][j] = grid[i-1][j-1] + pre[i-1][j+1];
            }
        }

        set<int> st; 

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                st.insert(grid[i-1][j-1]);
                if (st.size() > 3) st.erase(st.begin());

                for (int k = 1; i + 2 * k <= n && j - k >= 1 && j + k <= m; k++) {
                    // Top: (i, j), Bottom: (i+2k, j), Left: (i+k, j-k), Right: (i+k, j+k)
                    
                    int side1 = post[i + k][j + k] - post[i - 1][j - 1]; // Top to Right
                    int side2 = pre[i + k][j - k] - pre[i - 1][j + 1];   // Top to Left
                    int side3 = pre[i + 2 * k][j] - pre[i + k - 1][j + k + 1]; // Right to Bottom
                    int side4 = post[i + 2 * k][j] - post[i + k - 1][j - k - 1]; // Left to Bottom

                    int total = side1 + side2 + side3 + side4 - grid[i-1][j-1] - grid[i+2*k-1][j-1] - grid[i+k-1][j-k-1] - grid[i+k-1][j+k-1];

                    st.insert(total);
                    if (st.size() > 3) st.erase(st.begin());
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};