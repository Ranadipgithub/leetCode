class Solution {
public:
    static void sieve(int n, vector<bool>&isPrime){
        isPrime.assign(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2;p*p<=n;p++){
            if(isPrime[p]){
                for(int i = p*p;i<=n;i+=p){
                    isPrime[i] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        static vector<bool> isPrime;
        static bool built = false;
        if(!built){
            built = true;
            sieve(1e6, isPrime);
        }
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n, 0);
        visited[0] = 1;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int u = q.front();
                q.pop();

                if(u == n-1) return steps;
                if(u+1 < n && !visited[u+1]){
                    visited[u+1] = 1;
                    q.push(u+1);
                }
                if(u-1>=0 && !visited[u-1]){
                    visited[u-1] = 1;
                    q.push(u-1);
                }
                if(isPrime[nums[u]]){
                    for(int i = nums[u];i<=maxi;i+= nums[u]){
                        if(mpp.count(i)){
                            for(auto &idx: mpp[i]){
                                if(!visited[idx]){
                                    visited[idx] = 1;
                                    q.push(idx);
                                }
                            }
                            mpp.erase(i);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};