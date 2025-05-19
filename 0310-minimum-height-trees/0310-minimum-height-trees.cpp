class Solution {
public:
    int bfs(vector<vector<int>>& adj, int node) {
        vector<int> visited(adj.size(), 0); 
        queue<int> q;
        int level = 0;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop();
                for (int &v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
            level++;
        }

        return level - 1; 
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> adj(n);

        // for (auto &edge : edges) {
        //     int u = edge[0], v = edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // vector<int> res;
        // int minHeight = INT_MAX;

        // for (int i = 0; i < n; i++) {
        //     int height = bfs(adj, i); 
        //     if (height < minHeight) {
        //         res.clear();
        //         res.push_back(i);
        //         minHeight = height;
        //     } else if (height == minHeight) {
        //         res.push_back(i);
        //     }
        // }

        // return res;

        vector<vector<int>> adj(n);
        vector<int>indegree(n, 0);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        if(n == 1) return vector<int>{0};

        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(n > 2){
            int size = q.size();
            n -= size;
            while(size--){
                int u = q.front();
                q.pop();

                for(int &v: adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
        }
        return res;
    }
};
