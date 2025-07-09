class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &it:prerequisites ){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        

        queue<int> q;
        int cnt = 0;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};