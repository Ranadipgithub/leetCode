class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<set<int>> res(n);
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                indegree[v]--;
                res[v].insert(u);
                res[v].insert(res[u].begin(), res[u].end());
                if(indegree[v] == 0) q.push(v);
            }
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = vector<int>(res[i].begin(), res[i].end());
        }

        return ans;
    }
};