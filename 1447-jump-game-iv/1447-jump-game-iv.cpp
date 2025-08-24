class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        // unordered_map<int, vector<int>> adj;
        // for(int i = 0;i<n;i++){
        //     if(i+1 < n){
        //         adj[i].push_back(i+1);
        //     }
        //     if(i - 1 >= 0){
        //         adj[i].push_back(i-1);
        //     }
        //     if(mpp.count(arr[i])){
        //         for(auto it: mpp[arr[i]]){
        //             if(it != i){
        //                 adj[i].push_back(it);
        //             }
        //         }
        //     }
        // }
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
                    if(v == n-1) return ops+1;
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                    }
                }
                mpp[arr[idx]].clear();
                if(idx + 1 < n && !visited[idx+1]){
                    if(idx + 1 == n-1) return ops+1;
                    visited[idx+1] = 1;
                    q.push(idx + 1);
                }
                if(idx - 1 >= 0 && !visited[idx-1]){
                    if(idx - 1 == n-1) return ops+1;
                    visited[idx-1] = 1;
                    q.push(idx - 1);
                }
            }
            ops++;
        }
        return ops;
    }
};