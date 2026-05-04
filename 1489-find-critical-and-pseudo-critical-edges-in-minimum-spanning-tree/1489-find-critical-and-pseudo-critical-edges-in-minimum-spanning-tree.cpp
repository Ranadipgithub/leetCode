class Solution {
public:
    vector<int>parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]) return parent[x];
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) return;
        if(rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if(rank[parent_y] > rank[parent_x]) parent[parent_x] = parent_y;
        else {
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }
    }
    int kruskal(vector<vector<int>>& edges, int n, int blocked, int forced){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i<n;i++) parent[i] = i;
        int cost = 0, cntedge= 0;
        if(forced != -1){
            Union(edges[forced][0], edges[forced][1]);
            cost += edges[forced][2];
            cntedge++;
        }
        for(int i = 0;i<edges.size();i++){
            if(i == blocked) continue;
            if(find(edges[i][0]) == find(edges[i][1])) continue;
            cost += edges[i][2];
            cntedge++;
            Union(edges[i][0], edges[i][1]);
            if(cntedge == n-1) break;
        }
        return cntedge == n-1? cost: 1e9;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [&](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        int wt = kruskal(edges, n, -1, -1);
        vector<vector<int>> res(2);
        for(int i = 0;i<edges.size();i++){
            if(kruskal(edges, n, i, -1) > wt){
                res[0].push_back(edges[i][3]);
            } else if(kruskal(edges, n, -1, i) == wt) {
                res[1].push_back(edges[i][3]);
            }
        }
        return res;
    }
};