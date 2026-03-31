class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> adj;
        for(auto &path: paths){
            int u = path[0];
            int v = path[1];

            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        vector<int> res(n, 0);
        for(int i = 0;i<n;i++){
            vector<bool> used(5, false);
            for(int &v: adj[i]){
                if(res[v]){
                    used[res[v]] = true;
                }
            }
            for(int color = 1;color<=4;color++){
                if(!used[color]){
                    res[i] = color;
                    break;
                }
            }
        }
        return res;
    }
};