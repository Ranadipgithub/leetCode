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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int total = 0;
        for(int i = 0;i<n;i++){
            total += accounts[i].size();
        }
        parent.resize(total);
        rank.resize(total, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        unordered_map<string, int> mpp;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(mpp.count(accounts[i][j])){
                    unionSet(mpp[accounts[i][j]], i);
                }
                else mpp[accounts[i][j]] = i;
            }
        }

        vector<vector<string>> res;
        unordered_map<int, set<string>> st;
        for(auto it: mpp){
            int parent_x = find(it.second);
            st[parent_x].insert(it.first);
        }

        for(auto &it : st){
            int idx = it.first;
            vector<string> temp;
            temp.push_back(accounts[idx][0]);

            for(auto &email : it.second){
                temp.push_back(email);
            }

            res.push_back(temp);
        }
        return res;
    }
};