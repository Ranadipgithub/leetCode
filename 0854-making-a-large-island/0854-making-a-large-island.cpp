class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]) return x;
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
        } else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        parent.resize(n*m);
        for(int i = 0;i<n*m;i++){
            parent[i] = i;
        }
        rank.resize(n*m, 0);
        int cnt1 = 0, cnt0 = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]== 0) cnt0++;
                else cnt1++;
            }
        }
        if(cnt1 == n*m) return n*m;
        if(cnt0 == n*m) return 1;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    for(auto &dir: directions){
                        int newi = i + dir[0];
                        int newj = j + dir[1];

                        if(newi >= 0 && newi < n && newj >=0 && newj < m && grid[newi][newj] == 1){
                            unionSet(i*m+j, newi*m+newj);
                        }
                    }
                }
            }
        }

        unordered_map<int, int> mpp;
        for(int i = 0;i<n*m;i++){
            int par = find(i);
            mpp[par]++;
        }

        int maxarea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    int area = 0;
                    set<int> st;
                    for(auto &dir: directions){
                        int newi = i + dir[0];
                        int newj = j + dir[1];

                        if(newi >= 0 && newi < n && newj >=0 && newj < m && grid[newi][newj] == 1){
                            int par = find(newi*m+newj);
                            if(st.find(par) == st.end()){
                                area += mpp[par];
                                st.insert(par);
                            }
                        }
                    }
                    maxarea = max(area+1, maxarea);
                }
            }
        }
        return maxarea;
    }
};