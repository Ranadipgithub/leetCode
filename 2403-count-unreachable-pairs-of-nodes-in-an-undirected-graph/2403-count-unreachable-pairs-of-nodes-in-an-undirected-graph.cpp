class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y) return;
        
        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        } else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        } else{
            parent[parent_y] = parent_x;
            rank[parent_x]++; 
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            unionSet(u, v);
        }

        unordered_map<int,int> compSize;
        for(int i = 0; i < n; i++){
            int root = find(i);
            compSize[root]++;
        }

        long long ans = 0, total = n;
        for(auto &it : compSize){
            long long size = it.second;
            ans += size * (total - size);
        }

        return ans / 2;
    }
};