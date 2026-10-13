class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> res;

        while(!q.empty()){
            int course = q.front();
            q.pop();
            res.push_back(course);

            for(auto &ngbr: adj[course]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }
        if(res.size() != numCourses) return {};
        return res;
    }
};