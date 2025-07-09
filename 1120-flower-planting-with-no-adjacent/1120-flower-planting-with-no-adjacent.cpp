class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for (auto &p : paths) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> answer(n, 0);
        vector<bool> seen(n+1, false);
        
        for (int start = 1; start <= n; ++start) {
            if (seen[start]) continue;
            
            queue<int> q;
            q.push(start);
            answer[start-1] = 1;
            seen[start] = true;
            
            while (!q.empty()) {
                int u = q.front(); q.pop();
                
                for (int v : adj[u]) {
                    if (!seen[v]) {
                        bool used[5] = {false};
                        for (int w : adj[v]) {
                            if (answer[w-1] != 0)
                                used[ answer[w-1] ] = true;
                        }
                        for (int c = 1; c <= 4; ++c) {
                            if (!used[c]) {
                                answer[v-1] = c;
                                break;
                            }
                        }
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        
        return answer;
    }
};
