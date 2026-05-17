class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(arr[u] == 0) return true;
            if(arr[u] < 0) continue;
            int jump = arr[u];
            arr[u] = -arr[u];
            if(u+jump < n){
                q.push(u+jump);
            }
            if(u - jump >= 0){
                q.push(u-jump);
            }
        }
        return false;
    }
};