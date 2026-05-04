class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;
        if(rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if(rank[parent_x] < rank[parent_y]) parent[parent_x] = parent_y;
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i<n;i++) parent[i] = i;
        vector<vector<int>> edges;
        for(int i = 0;i<points.size();i++){
            for(int j = i+1;j<points.size();j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int cost = 0, cntEdge = 0;
        for(auto &edge: edges){
            if(find(edge[1]) == find(edge[2])) continue;
            cost += edge[0];
            Union(edge[1], edge[2]);
            cntEdge++;
            if(cntEdge == points.size()-1) break;
        }
        return cost;
    }
};