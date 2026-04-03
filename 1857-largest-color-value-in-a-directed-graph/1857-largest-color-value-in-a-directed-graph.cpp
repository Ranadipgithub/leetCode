class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        int cnt = 0, ans = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;

            dp[u][colors[u]-'a']++;
            ans = max(ans, dp[u][colors[u]-'a']);

            for(int &v: adj[u]){
                for(int i = 0;i<26;i++){
                    dp[v][i] = max(dp[v][i], dp[u][i]);
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }

        return cnt < n? -1: ans;
    }
};