class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph: a -> b (a is richer than b)
        for (auto &r : richer) {
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }

        // Kahn's algorithm (topo sort)
        queue<int> q;
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = i; // initially assume themselves as quietest
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                // propagate quietest person
                if (quiet[answer[u]] < quiet[answer[v]]) {
                    answer[v] = answer[u];
                }

                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return answer;
    }
};
