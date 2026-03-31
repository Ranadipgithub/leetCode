class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(node);
        color[node] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &v : graph[u]) {
                if (color[v] == color[u]) return false;
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1); 
        for (const auto& pair : dislikes) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> color(n + 1, -1); 
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                if (!bfs(graph, i, color, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0]-1, v= edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(!possibleBipartition(n, edges)) return -1;

        vector<int> dist(n, 0);
        for(int i = 0;i<n;i++){
            int cnt = 0;
            queue<int> q;
            q.push(i);
            vector<int> visited(n, 0);
            visited[i] = 1;
            
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    int u = q.front();
                    q.pop();

                    for(int &v: adj[u]){
                        if(!visited[v]){
                            visited[v] = 1;
                            q.push(v);
                        }
                    }
                }
                cnt++;
            }
            dist[i] = cnt;
        }
        
        int grps = 0;
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                int maxi = 0;

                while(!q.empty()){
                    int u = q.front();
                    q.pop();

                    maxi = max(maxi, dist[u]);
                    for(int &v: adj[u]){
                        if(!visited[v]){
                            visited[v] = 1;
                            q.push(v);
                        }
                    }
                }
                grps += maxi;
            }
        }
        return grps;
    }
};