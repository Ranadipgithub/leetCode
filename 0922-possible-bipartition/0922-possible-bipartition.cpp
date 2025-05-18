class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(node);
        color[node] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &v : graph[u]) {
                if (color[v] == color[u]) return false;
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1); 
        for (const auto& pair : dislikes) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> color(n + 1, -1); 
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                if (!bfs(graph, i, color, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};
