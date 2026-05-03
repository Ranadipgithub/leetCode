class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        components = n;
        for(int i = 1;i<=n;i++) parent[i] = i;
    }
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x  == parent_y) return;
        if(rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if (rank[parent_x] < rank[parent_y]) parent[parent_x] = parent_y;
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        components--;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        // sort(edges.begin(), edges.end(), [&](vector<int>&a, vector<int>&b){
        //     return a[0] > b[0];
        // });

        int cnt = 0;
        for(auto &edge: edges){
            int type = edge[0], u = edge[1], v = edge[2];
            if(type == 3){
                bool fg = false;
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u, v);
                    fg = true;
                } 
                if(bob.find(u) != bob.find(v)){
                    bob.Union(u, v);
                    fg = true;
                }
                if(fg) cnt++;
            } 
        }
        for(auto &edge: edges){
            int type = edge[0], u = edge[1], v = edge[2];
            if(type == 2){
                if(bob.find(u) != bob.find(v)){
                    bob.Union(u, v);
                    cnt++;
                }
            } else {
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u, v);
                    cnt++;
                } 
            }
        }
        if(alice.components != 1 || bob.components != 1) return -1;
        return edges.size() - cnt;
    }
};