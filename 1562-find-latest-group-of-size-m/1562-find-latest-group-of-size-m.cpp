class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

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
            size[parent_x] += size[parent_y];
            size[parent_y] = 0;
        } else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
            size[parent_x] = 0;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
            size[parent_x] += size[parent_y];
            size[parent_y] = 0;
        }
    }

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 0);

        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        int step = -1;
        for(int i = 0;i<n;i++){
            int pos = arr[i];
            size[find(pos)] = 1;

            if (pos > 1 && size[find(pos - 1)] == m) step = i;
            if (pos < n && size[find(pos + 1)] == m) step = i;

            if (pos > 1 && size[find(pos - 1)] > 0) unionSet(pos, pos - 1);
            if (pos < n && size[find(pos + 1)] > 0) unionSet(pos, pos + 1);
        }
        return step;
    }
};