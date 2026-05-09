class Solution {
public:
    bool isPossible(int mid, int n, vector<vector<pair<int, int>>> &adj, int src, int target, int k){
        vector<int> res(n, INT_MAX);
        res[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            int u = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();
            
            if (cnt > res[u]) continue;
            if(u == target){
                return cnt <= k;
            }
            
            for(auto it: adj[u]){
                int v = it.first;
                int newCnt = cnt + (it.second > mid);
                if(newCnt < res[v]){
                    res[v] = newCnt;
                    pq.push({newCnt, v});
                }
            }
        }
        return false;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int, int>>> adj(n);
        int high = 1;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            high = max(high, w);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int low = 0;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, n, adj, source, target, k)){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};