class Solution {
public:
    void dfs(int i, int node, unordered_map<int, vector<int>>& adj, vector<int>& visited, set<int>& st, vector<int>& belong) {
        visited[node] = 1;
        st.insert(node);
        belong[node] = i;
        for (auto& ngbr : adj[node]) {
            if (!visited[ngbr]) {
                dfs(i, ngbr, adj, visited, st, belong);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : connections) { 
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(c + 1, 0);
        vector<int> belong(c + 1);
        unordered_map<int, set<int>> st;
        
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                set<int> temp;
                dfs(i, i, adj, visited, temp, belong);
                st[i] = temp;
            }
        }

        vector<int> res;
        for (auto& it : queries) {
            int type = it[0];
            int x = it[1];
            int grp = belong[x];

            if (type == 2) {
                st[grp].erase(x);
            } else { 
                if (st[grp].count(x)) {
                    res.push_back(x);
                } else {
                    if (st[grp].empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*st[grp].begin());
                    }
                }
            }
        }
        return res;
    }
};