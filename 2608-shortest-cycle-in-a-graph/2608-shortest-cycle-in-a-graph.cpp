class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int minLen = INT_MAX;
        
        for(int i = 0; i < n; i++){ 
            vector<int> dist(n, -1);
            dist[i] = 0;
            queue<pair<int, int>> q;
            q.push({i, -1});

            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int u = it.first, parent = it.second;

                for(int &v: adj[u]){
                    if(dist[v] == -1){ 
                        dist[v] = dist[u] + 1;
                        q.push({v, u});
                        continue;
                    }
                    if(v != parent){
                        minLen = min(minLen, dist[u] + dist[v] + 1); 
                    }
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};