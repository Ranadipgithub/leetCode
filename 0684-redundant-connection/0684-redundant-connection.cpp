class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)){
                return edge; 
            }
            unionSet(u, v);
        }
        return {};
    }
};