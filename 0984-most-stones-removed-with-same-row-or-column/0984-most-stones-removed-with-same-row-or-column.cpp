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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){ 
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unionSet(i, j);
                }
            }
        }

        int grps = 0;
        for(int i = 0; i < n; i++){
            if(find(i) == i) grps++;
        }
        return n - grps;
    }
};