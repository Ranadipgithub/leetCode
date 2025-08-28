class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &it: roads){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;

        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > dist[node]) continue;

            for(auto &ngbr: adj[node]){
                int v = ngbr.first;
                int w = ngbr.second;

                if(dist[v] > cost + w){
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                    cnt[v] = cnt[node];
                } 
                else if(dist[v] == cost + w){
                    cnt[v] = (cnt[v] + cnt[node]) % MOD;
                }
            }
        }
        return cnt[n-1] % MOD;
    }
};