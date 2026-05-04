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
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<pair<int, pair<int, int>>> edgeList;
        edgeList.reserve(n * (n - 1) / 2); 

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edgeList.push_back({dist, {i, j}});
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(edgeList.begin(), edgeList.end());

        int cost = 0, cntEdge = 0;
        while (cntEdge < n - 1) {
            auto top = pq.top();
            pq.pop();
            
            int wt = top.first;
            int u = top.second.first;
            int v = top.second.second;

            if (find(u) != find(v)) {
                cost += wt;
                Union(u, v);
                cntEdge++;
            }
        }
        return cost;
    }
};