class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>&adj, vector<int>&visited, unordered_set<int>&subset){
        visited[node] = 1;
        for(auto &ngbr: adj[node]){
            if(!visited[ngbr] && subset.count(ngbr)){
                dfs(ngbr, adj, visited, subset);
            }
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n = nums.size();
        int cnt = 0;
        for(int i = 1;i<(1<<n);i++){
            unordered_set<int> subset;
            long long sum = 0;
            for(int j = 0;j<n;j++){
                if((i & (1<<j)) != 0){
                    subset.insert(j);
                    sum += nums[j];
                } 
            }
            if(sum%2 != 0) continue;

            vector<int> visited(n, 0);
            int el = *subset.begin();
            dfs(el, adj, visited, subset);
            bool fg = true;
            for(auto it: subset){
                if(visited[it] != 1){
                    fg = false;
                    break;
                }
            }
            if(fg) cnt++;
        }
        return cnt;
    }
};