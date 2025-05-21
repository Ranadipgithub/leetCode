class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0); 
        vector<vector<pair<int, double>>> adj(n); 

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<double, int>> pq;
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) return currProb;

            for (auto &[ngbr, wt] : adj[node]) {
                if (prob[node] * wt > prob[ngbr]) {
                    prob[ngbr] = prob[node] * wt;
                    pq.push({prob[ngbr], ngbr});
                }
            }
        }

        return 0.0;
    }
};
