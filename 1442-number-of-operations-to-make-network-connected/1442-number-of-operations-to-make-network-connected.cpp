class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y) return;
        if(rank[parent_x] < rank[parent_y]){
            parent[parent_y] = parent_x;
        } else if(rank[parent_x] > rank[parent_y]){
            parent[parent_x] = parent_y;
        } else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noOfEdges = connections.size();
        if(noOfEdges < n-1)  return -1;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        int components = n;
        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u != parent_v){
                components--;
                Union(u, v);
            }
        }
        return components-1;
    }
};