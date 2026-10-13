class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0;i<routes.size();i++){
            for(int j = 0;j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int> visited;
        vector<int> visitedRoute(routes.size(), 0);
        queue<int> q;
        q.push(source);
        visited.insert(source);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int stop = q.front();
                q.pop();

                if(stop == target) return cnt;
                for(auto &it: adj[stop]){
                    if(visitedRoute[it]) continue;
                    visitedRoute[it] = 1;
                    for(auto &ngbr: routes[it]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};