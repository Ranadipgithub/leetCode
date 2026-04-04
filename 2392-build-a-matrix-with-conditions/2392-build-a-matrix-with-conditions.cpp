class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdj(k);
        vector<int> rowIndeg(k, 0);
        for(auto &edge: rowConditions){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            rowAdj[u].push_back(v);
            rowIndeg[v]++;
        }
        unordered_map<int,int> row;
        queue<int> q;
        for(int i = 0; i < k; i++){
            if(rowIndeg[i] == 0) q.push(i);
        }
        int idx = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            row[u] = idx++;

            for(int v: rowAdj[u]){
                if(--rowIndeg[v] == 0) q.push(v);
            }
        }
        if(row.size() != k) return {};

        vector<vector<int>> colAdj(k);
        vector<int> colIndeg(k, 0);
        for(auto &edge: colConditions){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            colAdj[u].push_back(v);
            colIndeg[v]++;
        }
        unordered_map<int,int> col;
        queue<int> q2;
        for(int i = 0; i < k; i++){
            if(colIndeg[i] == 0) q2.push(i);
        }
        idx = 0;
        while(!q2.empty()){
            int u = q2.front(); q2.pop();
            col[u] = idx++;

            for(int v: colAdj[u]){
                if(--colIndeg[v] == 0) q2.push(v);
            }
        }

        if(col.size() != k) return {};
        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++){
            res[row[i]][col[i]] = i + 1;
        }

        return res;
    }
};