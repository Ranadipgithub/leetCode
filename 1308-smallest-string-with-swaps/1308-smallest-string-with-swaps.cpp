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
        } else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(auto pair: pairs){
            unionSet(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            int par = find(i);
            mpp[par].push_back(i);
        }

        string res = s;
        for(auto it: mpp){
            vector<int> indices = it.second;
            string temp = "";
            for(int idx: indices){
                temp += s[idx];
            }
            sort(temp.begin(), temp.end());
            sort(indices.begin(), indices.end());

            for(int i = 0;i<indices.size();i++){
                res[indices[i]] = temp[i];
            }
        }
        return res;
    }
};