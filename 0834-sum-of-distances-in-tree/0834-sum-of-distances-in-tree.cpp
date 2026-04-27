class Solution {
public:
    vector<int> child;
    int cntChild(int node, int parent, vector<vector<int>> &adj){
        int cnt = 0;
        for(auto &ngbr: adj[node]){
            if(ngbr == parent) continue;
            cnt += cntChild(ngbr, node, adj);
        }
        child[node] = cnt + 1;
        return child[node];
    }
    int solve(int node, vector<vector<int>> &adj,  int n){
        queue<int> q;
        q.push(node);
        vector<int> visited(n, 0);
        visited[node] = 1;
        int dist = 0, level = 0;
        while(!q.empty()){
            int size = q.size();
            dist += size * level;
            while(size--){
                int u = q.front();
                q.pop();

                for(auto &v: adj[u]){
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
            level++;
        }
        return dist;
    }
    void bfs(int node, int parent, vector<vector<int>> &adj, int rootCnt, int n, vector<int>&res){
        for(auto &v: adj[node]){
            if(v == parent) continue;
            int cntChilds = child[v];
            res[v] = rootCnt - cntChilds + (n-cntChilds);
            bfs(v, node, adj, res[v], n, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        child.resize(n, 0);
        for(auto &edge: edges){
            int u = edge[0], v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cntChild(0, -1, adj);
        vector<int> res(n, 0);
        int rootCnt = solve(0, adj, n);
        res[0] = rootCnt;
        bfs(0, -1, adj, rootCnt, n, res);
        return res;
    }
};