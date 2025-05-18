class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);  // b → a
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto &v: adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return (res.size() == numCourses) ? res : vector<int>{};
    }
};
