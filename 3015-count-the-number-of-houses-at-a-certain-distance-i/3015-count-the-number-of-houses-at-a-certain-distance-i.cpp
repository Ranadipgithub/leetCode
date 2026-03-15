class Solution {
public:
    void bfs(int node, vector<int>&res, unordered_map<int, vector<int>> &adj){
        queue<int> q;
        q.push(node);
        vector<int> visited(res.size()+1, 0);
        visited[node] = 1;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int u = q.front();
                q.pop();

                for(int v: adj[u]){
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                        res[dist]++;
                    }
                }
            }
            dist++;
        }
    }
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int, vector<int>> adj;
        for(int i = 1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> res(n, 0);
        for(int i = 1;i<=n;i++){
            bfs(i, res, adj);
        }
        return res;
    }
};