class Solution {
public:
    int dijkstra(int u, int v, int total, vector<vector<pair<int, long long>>> &adj){
        vector<long long> dist(total, INT_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, u});
        dist[u] = 0;
        while(!pq.empty()){
            long long node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if(d > dist[node]) continue;
            if(node == v) return d;
            for(auto &it: adj[node]){
                long long ngbr = it.first;
                long long wt = it.second;
                if(dist[node] + wt < dist[ngbr]){
                    dist[ngbr] = dist[node] + wt;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }
        return -1;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(2*n);
        for(auto &edge: roads){
            int u = edge[0], v = edge[1], w = edge[2],tax = edge[3];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            adj[u+n].push_back({v+n, (long long)w*tax});
            adj[v+n].push_back({u+n, (long long)w*tax});
        }
        for(int i = 0;i<n;i++){
            adj[i].push_back({i+n, (long long)prices[i]});
        }
        vector<int> res(n);
        for(int i = 0;i<n;i++){
            res[i] = dijkstra(i, i+n, 2*n, adj);
        }
        return res;
    }
};