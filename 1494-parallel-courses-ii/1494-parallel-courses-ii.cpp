class Solution {
public:
    int n, k;
    vector<int> dp;
    int solve(int mask, vector<vector<int>> &adj){
        if(mask == (1<<n)-1) return 0;
        if(dp[mask] != -1) return dp[mask];
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)) continue;
            for(int &v: adj[i]){
                if(!(mask & (1<<v))) {
                    indegree[v]++;
                }
            }
        }
        int avail_mask = 0; // identifies which courses are currently available to take
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0 && !(mask & (1<<i))){
                avail_mask |= (1<<i);
            }
        }

        int num_avail = __builtin_popcount(avail_mask);
        int taken = n+1;
        if(num_avail > k){
            // we have to try every combination of exactly k courses
            // that is we have to find the submasks of the mask which has exactly k set bits
            int m = avail_mask;
            for(int s = m;s>0;s=(s-1)&m){
                if(__builtin_popcount(s) == k){
                    taken = min(taken, 1 + solve(mask | s, adj));
                }
            }
        } else {
            taken = min(taken, 1 + solve(mask|avail_mask, adj));
        }
        return dp[mask] = taken;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int>> adj(n);
        for(auto &edge: relations){
            int u = edge[0]-1;
            int v = edge[1] -1;
            adj[u].push_back(v);
        }

        dp.assign((1<<n), -1);

        int mask = 0; // no of courses that are finished
        return solve(mask, adj);
    }
};