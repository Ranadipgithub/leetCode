class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y) return;

        if (rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        } else if (rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; ++i) parent[i] = i;

        // First pass: process all equalities
        for (string& s : equations){
            if (s[1] == '='){
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        // Second pass: check inequalities
        for (string& s : equations){
            if (s[1] == '!'){
                int parent_a = find(s[0] - 'a');
                int parent_b = find(s[3] - 'a');
                if (parent_a == parent_b) return false;
            }
        }

        return true;
    }
};
