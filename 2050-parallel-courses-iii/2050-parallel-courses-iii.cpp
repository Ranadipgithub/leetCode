class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &edge: relations){
            int u = edge[0]-1, v = edge[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> maxiTime = time;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                maxiTime[v] = max(maxiTime[v], maxiTime[u]+time[v]);
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return *max_element(maxiTime.begin(), maxiTime.end());
    }
};