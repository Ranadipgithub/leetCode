class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        vector<bool> pruned(n, false);

        for(int i = 0;i<n;i++){
            if(edges[i] != -1){
                indegree[edges[i]]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            pruned[u] = true;

            int v = edges[u];
            if(v != -1){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        int maxLen = -1;
        for(int i = 0;i<n;i++){
            if(!pruned[i]){
                int curr = i, len = 0;
                while(!pruned[curr]){
                    pruned[curr] = 1;
                    curr = edges[curr];
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};