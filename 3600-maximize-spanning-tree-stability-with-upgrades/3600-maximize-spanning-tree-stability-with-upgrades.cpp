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

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        } else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    bool isPossible(int n, vector<vector<int>>& edges, int k, int mid){
        parent.assign(n+1, 0);
        rank.assign(n+1, 0);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        vector<vector<int>> cand;

        for(auto &edge: edges){
            int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
            if(m == 1){
                if(s < mid){
                    return false;
                } 
                unionSet(u, v);
            } else {
                if(s >= mid){
                    unionSet(u, v);
                } else if(2*s >= mid){
                    cand.push_back({u, v});
                }
            }
        }

        for(auto &edge: cand){
            int u = edge[0], v = edge[1];

            if(find(u) != find(v)){
                if(k <= 0) return false;
                unionSet(u, v);
                k--;
            }
        }

        int root = find(0);
        for(int i = 1;i<n;i++){
            if(find(i) != root) return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(auto &edge: edges){
            int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
            if(m == 1){
                if(find(u) == find(v)){
                    return -1;
                }
                unionSet(u, v);
            }
        }

        int res = -1;
        int low = 0, high = 2*1e5;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(n, edges, k, mid)){
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};