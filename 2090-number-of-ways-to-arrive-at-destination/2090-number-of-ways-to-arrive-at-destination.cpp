class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : roads) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        vector<long long> minTime(n, LLONG_MAX);
        vector<int> cnt(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        minTime[0] = 0;
        cnt[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while(!pq.empty()) {
            auto [currTime, node] = pq.top(); pq.pop();

            if (currTime > minTime[node]) continue; 

            for (auto &[ngbr, wt] : adj[node]) {
                if (minTime[node] + wt < minTime[ngbr]) {
                    minTime[ngbr] = minTime[node] + wt;
                    cnt[ngbr] = cnt[node];
                    pq.push({minTime[ngbr], ngbr});
                } else if (minTime[node] + wt == minTime[ngbr]) {
                    cnt[ngbr] = (cnt[ngbr] + cnt[node]) % mod;
                }
            }
        }

        return cnt[n - 1];
    }
};
