class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &edge: prerequisites){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<unordered_set<int>> mpp(numCourses);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int &ngbr: adj[node]){
                mpp[ngbr].insert(node);
                for(auto &p: mpp[node]){
                    mpp[ngbr].insert(p);
                }
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) q.push(ngbr);
            }
        }
        vector<bool> res;
        for(auto &q: queries){
            int u = q[0], v = q[1];
            if(mpp[v].count(u)) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};