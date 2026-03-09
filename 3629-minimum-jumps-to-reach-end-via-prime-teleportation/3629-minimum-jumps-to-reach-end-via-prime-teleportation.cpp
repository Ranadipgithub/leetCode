class Solution {
public:
    unordered_map<int, vector<int>> mpp;
    unordered_map<int, vector<int>> adj;
    
    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
                
                if (mpp.count(i)) {
                    for (int j = i; j <= n; j += i) {
                        if (mpp.count(j)) {
                            for (int idx : mpp[j]) {
                                adj[i].push_back(idx); 
                            }
                        }
                    }
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        int maxi = *max_element(nums.begin(), nums.end());
        sieve(maxi);

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;
        
        int cnt = 0; 
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int u = q.front();
                q.pop();

                if(u == n-1) return cnt;

                if(u+1 < n && !visited[u+1]) {
                    visited[u+1] = 1;
                    q.push(u+1);
                }

                if(u-1 >= 0 && !visited[u-1]){
                    visited[u-1] = 1;
                    q.push(u-1);
                }

                for(int v: adj[nums[u]]){
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                    }
                }
                adj[nums[u]].clear(); 
            }
            cnt++;
        }
        return cnt;
    }
};