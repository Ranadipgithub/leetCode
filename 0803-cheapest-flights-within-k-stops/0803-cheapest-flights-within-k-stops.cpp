class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &it: flights){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int steps = 0;
        while(!q.empty() && steps <= k){
            int size = q.size();
            while(size--){
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                
                for(auto &ngbr: adj[node]){
                    int v = ngbr.first;
                    int w = ngbr.second;

                    if(dist[v] > cost + w){
                        dist[v] = cost + w;
                        q.push({v, dist[v]});
                    }
                }
            }
            steps++;
        }
        return dist[dst] == INT_MAX? -1: dist[dst];
    }
};