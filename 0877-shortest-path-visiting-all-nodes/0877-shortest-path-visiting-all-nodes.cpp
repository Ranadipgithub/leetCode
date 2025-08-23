class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return ((size_t)p.first << 32) ^ p.second;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        int n = graph.size();
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        queue<pair<int, int>> q; // node, mask
        unordered_set<pair<int,int>, PairHash> visited;

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited.insert({i, 1 << i});
        }

        int ops = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == (1 << n) - 1) return ops;

                for (int v : adj[node]) {
                    int nextmask = mask | (1 << v);
                    if (nextmask == (1 << n) - 1) return ops + 1;
                    if (!visited.count({v, nextmask})) {
                        visited.insert({v, nextmask});
                        q.push({v, nextmask});
                    }
                }
            }
            ops++;
        }
        return ops;
    }
};
