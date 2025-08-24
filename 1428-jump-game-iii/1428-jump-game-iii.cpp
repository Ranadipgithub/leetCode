class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, vector<int>> adj;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(i+arr[i] < n){
                adj[i].push_back(i+arr[i]);
            }
            if(i - arr[i] >= 0){
                adj[i].push_back(i-arr[i]);
            }
        }
        queue<int> q;
        q.push(start);
        vector<int> visited(n, 0);
        visited[start] = 1;
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;
            for(int v: adj[idx]){
                if(arr[v] == 0) return true;
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        return false;
    }
};