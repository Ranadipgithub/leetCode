class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> visited(n, 0);
        visited[start] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(arr[u] == 0) return true;
            if(u+arr[u] < n){
                if(!visited[u+arr[u]]){
                    visited[u+arr[u]] = 1;
                    q.push(u+ arr[u]);
                }
            }
            if(u - arr[u] >= 0){
                if(!visited[u-arr[u]]){
                    visited[u-arr[u]] = 1;
                    q.push(u- arr[u]);
                }
            }
        }
        return false;
    }
};