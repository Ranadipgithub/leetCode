class Solution {
public:
    void solve(int node, int target, vector<vector<int>>& graph, vector<int> &temp, vector<vector<int>> &res){
        if(node == target){
            res.push_back(temp);
            return;
        }
        for(int v: graph[node]){
            temp.push_back(v);
            solve(v, target, graph, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(0);
        solve(0, n-1, graph, temp, res);
        return res;
    }
};