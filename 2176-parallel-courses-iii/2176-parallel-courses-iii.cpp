class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);
        
        for (auto& it : relations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> completion(n + 1, 0); 

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                completion[i] = time[i - 1];  
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                indegree[v]--;
                completion[v] = max(completion[v], completion[u] + time[v - 1]);  // again time is 0-based
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return *max_element(completion.begin(), completion.end());
    }
};
