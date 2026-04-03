class Solution {
public:
    vector<int> topoSort(int count, vector<int>& indegree, unordered_map<int, vector<int>>& adj) {
        vector<int> order;
        queue<int> q;
        for (int i = 0; i < count; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        return order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupCount = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) group[i] = groupCount++;
        }

        unordered_map<int, vector<int>> itemAdj, grpAdj;
        vector<int> itemIndegree(n, 0), grpIndegree(groupCount, 0);

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemAdj[prev].push_back(i);
                itemIndegree[i]++;
                
                if (group[i] != group[prev]) {
                    grpAdj[group[prev]].push_back(group[i]);
                    grpIndegree[group[i]]++;
                }
            }
        }

        vector<int> itemOrder = topoSort(n, itemIndegree, itemAdj);
        vector<int> grpOrder = topoSort(groupCount, grpIndegree, grpAdj);

        if (itemOrder.size() != n || grpOrder.size() != groupCount) return {};
        unordered_map<int, vector<int>> itemsInGroup;
        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        vector<int> ans;
        for (int gId : grpOrder) {
            for (int item : itemsInGroup[gId]) {
                ans.push_back(item);
            }
        }

        return ans;
    }
};