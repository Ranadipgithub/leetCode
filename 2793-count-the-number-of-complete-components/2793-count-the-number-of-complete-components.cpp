class Solution {
public:
    // no of edges = n*(n-1)/2;
    // degree of each node = n-1;
    void dfs(int node, vector<int>& visited, unordered_map<int, vector<int>> &adj, int &nodes, int &edges){
        visited[node] = 1;
        nodes++;
        for(auto &ngbr: adj[node]){
            edges++;
            if(!visited[ngbr]){
                dfs(ngbr, visited, adj, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int nodes = 0, edges = 0;
                dfs(i, visited, adj, nodes, edges);

                edges /= 2; // because each undirected edge counted twice
                if(edges == nodes * (nodes - 1) / 2) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
