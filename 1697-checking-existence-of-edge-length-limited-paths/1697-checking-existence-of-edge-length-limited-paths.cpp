class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;
        if(rank[parent_x] > rank[parent_y]) parent[parent_y] = parent_x;
        else if(rank[parent_x] < rank[parent_y]) parent[parent_x] = parent_y;
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        for(int i = 0;i<n;i++) parent[i] = i;
        sort(edgeList.begin(), edgeList.end(), [&](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        sort(queries.begin(), queries.end(), [&](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        vector<bool> res(queries.size(), false);
        int i = 0;
        for(auto &query: queries){
            int u = query[0], v = query[1], w = query[2], idx = query[3];
            
            while(i<edgeList.size() && edgeList[i][2] < w){
                unionSet(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            if(find(u) == find(v)){
                res[idx] = true;
            }
        }
        return res;
    }
};