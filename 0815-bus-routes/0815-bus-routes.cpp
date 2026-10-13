class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> adj;
        for(int i = 0;i<routes.size();i++){
            for(int j = 0;j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }
        }
        
        vector<int> visited(routes.size(), 0);
        queue<pair<int, int>> q;
        for(auto &route: adj[source]){
            q.push({route, 1});
            visited[route] = 1;
        }

        while(!q.empty()){
            int route = q.front().first;
            int busCnt = q.front().second;
            q.pop();

            for(int &stop: routes[route]){
                if(stop == target) return busCnt;

                for(auto &ngbr: adj[stop]){
                    if(!visited[ngbr]){
                        q.push({ngbr, busCnt+1});
                        visited[ngbr] = 1;
                    }
                }
            }
        }
        return -1;
    }
};