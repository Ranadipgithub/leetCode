class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        int n = prerequisites.size();
        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];

            // b ---> a
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto &v: adj[i]){
                indegree[v]++;
            }
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