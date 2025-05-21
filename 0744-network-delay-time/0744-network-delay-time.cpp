class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<int> explored(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            if(explored[node]) continue;
            explored[node] = 1;

            for (auto &edge : adj[node]) {
                int ngbr = edge.first, wt = edge.second;
                if (!explored[ngbr] && dist[node] + wt < dist[ngbr]) {
                    dist[ngbr] = dist[node] + wt;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
