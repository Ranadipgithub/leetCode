class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, char ch, vector<bool>& visited, char &ch1) {
        visited[ch - 'a'] = true;
        if (ch < ch1) ch1 = ch;
        for (auto nxt : adj[ch]) {
            if (!visited[nxt - 'a']) {
                dfs(adj, nxt, visited, ch1);
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        for (int i = 0; i < m; i++) {
            char start = baseStr[i];
            vector<bool> visited(26, false);
            char ch1 = start; 
            dfs(adj, start, visited, ch1);
            baseStr[i] = ch1;
        }

        return baseStr;
    }
};
