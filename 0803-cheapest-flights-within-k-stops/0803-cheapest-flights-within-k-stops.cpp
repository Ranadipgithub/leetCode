class Solution {
public:
    typedef pair<int, int> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : flights) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;
        int steps = 0;
        while(!q.empty() && steps <= k){
            int size = q.size();
            while(size--){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for(auto &ngbr: adj[u]){
                    int v = ngbr.first;
                    int cost = ngbr.second;
                    if(dist[v] > d+cost){
                        dist[v] = d+cost;
                        q.push({v, dist[v]});
                    }
                }
            }
            steps++;
        }
        return dist[dst] == INT_MAX? -1 : dist[dst];
    }
};
