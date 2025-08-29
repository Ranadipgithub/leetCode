class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1,0}, {0, 1}};
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        } else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        rank.resize(n*m, 0);
        parent.resize(n*m);
        for(int i = 0;i<n*m;i++){
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    for(auto &dir: directions){
                        int newi = i + dir[0];
                        int newj = j + dir[1];

                        if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] == '1'){
                            unionSet(i*m+j, newi*m+newj);
                        }
                    }
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    st.insert(find(i*m+j));
                }
            }
        }
        return st.size();
    }
};