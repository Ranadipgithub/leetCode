class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &it: times){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            for(auto &ngbr: adj[node]){
                int v = ngbr.first;
                int w = ngbr.second;

                if(dist[v] > wt + w){
                    dist[v] = wt+w;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = *max_element(dist.begin()+1, dist.end());
        return res == INT_MAX? -1: res;
    }
};