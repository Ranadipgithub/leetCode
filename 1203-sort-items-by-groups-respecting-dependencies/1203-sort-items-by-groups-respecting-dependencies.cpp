class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, int> grps;
        int k = m;
        for(int i = 0; i < n; i++){
            if(group[i] == -1) grps[i] = k++;
            else grps[i] = group[i];
        }

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < beforeItems[i].size(); j++){
                adj[beforeItems[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);

        vector<int> itemOrder;
        while(!q.empty()){
            int u = q.front(); q.pop();
            itemOrder.push_back(u);
            for(int v : adj[u]){
                if(--indegree[v] == 0) q.push(v);
            }
        }

        unordered_map<int, vector<int>> grp_adj;
        vector<int> grp_indegree(k, 0);
        for(int i = 0; i < n; i++){
            int u = grps[i];
            for(int j = 0; j < beforeItems[i].size(); j++){
                int v = grps[beforeItems[i][j]];
                if(u != v){ 
                    grp_adj[v].push_back(u);
                    grp_indegree[u]++;
                }
            }
        }

        queue<int> gq; 
        for(int i = 0; i < k; i++) if(grp_indegree[i] == 0) gq.push(i);

        vector<int> grpOrder;
        while(!gq.empty()){
            int u = gq.front(); gq.pop();
            grpOrder.push_back(u);
            for(int v : grp_adj[u]){
                if(--grp_indegree[v] == 0) gq.push(v);
            }
        }
        
        unordered_map<int, vector<int>> res;
        for(int item : itemOrder){
            res[grps[item]].push_back(item);
        }

        vector<int> ans;
        for(int gId : grpOrder){
            for(int item : res[gId]){
                ans.push_back(item);
            }
        }

        return (ans.size() == n) ? ans : vector<int>{};
    }
};