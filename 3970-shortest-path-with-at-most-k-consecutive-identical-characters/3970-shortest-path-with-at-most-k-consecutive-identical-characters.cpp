class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // we have to find the shortest path from src 0 to node n-1: dijkstra
        // we have to track the current charcter and it's occurance
        // dp[i] = shortest path from src to i
        // dp[i][k] = shortest path from src to i such that the path contains exactly k consecutive characters
        // ans = min(dp[n-1][1], dp[n-1][2], ..., dp[n-1][k])
        // if the current node contains the same character as prev then dp[v][cnt+1] = dp[u][cnt] + wt 
        // else dp[v][1] = dp[u][cnt] + wt 
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX));
        dp[0][1] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 1}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first, u = top.second.first, cnt = top.second.second;
            if(u == n-1) return d;
            for(auto &edge: adj[u]){
                int v = edge.first, w = edge.second;
                if(labels[u] != labels[v]){
                    if(d + w < dp[v][1]){
                        dp[v][1] = d + w;
                        pq.push({dp[v][1], {v, 1}});
                    }
                } else {
                    int newCnt = cnt + 1;
                    if(newCnt <= k && d + w < dp[v][newCnt]){
                        dp[v][newCnt] = d + w;
                        pq.push({dp[v][newCnt], {v, newCnt}});
                    }
                }
            }
        }
        return -1;
    }
};