class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // applying bfs from each node is time taking and will result into tle
        // better approach is to figure out which nodes can be our potential root node
        // the nodes which are at the middle have the high chance to be the root of the MHT
        // there can be either 2 middle nodes or 1 middle node
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(degree[i] == 1) q.push(i);
        }
        int rem = n;
        while(rem > 2){
            int size = q.size();
            rem -= size;
            while(size--){
                int u = q.front();
                q.pop();

                for(int &v: adj[u]){
                    degree[v] -= 1;
                    if(degree[v] == 1) q.push(v);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};