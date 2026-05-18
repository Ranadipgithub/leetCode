class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n, 0);
        visited[0] = 1;
        int ops = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int idx = q.front();
                q.pop();

                if(idx == n-1) return ops;
                for(int v: mpp[arr[idx]]){
                    if(!visited[v] && v != idx){
                        visited[v] = 1;
                        q.push(v);
                    }
                }
                mpp[arr[idx]].clear();
                if(idx + 1 < n && !visited[idx+1]){
                    visited[idx+1] = 1;
                    q.push(idx + 1);
                }
                if(idx - 1 >= 0 && !visited[idx-1]){
                    visited[idx-1] = 1;
                    q.push(idx - 1);
                }
            }
            ops++;
        }
        return ops;
    }
};