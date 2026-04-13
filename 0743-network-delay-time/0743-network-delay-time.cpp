class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &edge: times){
            int u = edge[0]-1, v = edge[1]-1, w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> res(n, INT_MAX);
        res[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});
        while(!pq.empty()){
            int u = pq.top().second;
            int wtu = pq.top().first;
            pq.pop();
            if(res[u] < wtu) continue;

            for(auto it: adj[u]){
                int v = it.first, wtv = it.second;
                if(wtu+wtv < res[v]){
                    res[v] = wtu + wtv;
                    pq.push({wtu+wtv, v});
                }
            }
        }

        for(auto it: res){
            if(it == INT_MAX) return -1;
        }
        return *max_element(res.begin(), res.end());
    }
};