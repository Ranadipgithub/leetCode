class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto &req : requests) {
            diff[req[0]]++;
            if(req[1] + 1 < n) diff[req[1] + 1]--;
        }
        vector<int> res(n, 0);
        res[0] = diff[0];
        for(int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i];
        }

        sort(nums.begin(), nums.end(), greater<int>());
        vector<pair<int, int>> temp;
        for(int i = 0;i<res.size();i++){
            temp.push_back({res[i], i});
        }
        sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        vector<int> ans(n);
        int j = 0;
        for(int i = 0;i<n;i++){
            ans[temp[i].second] = nums[j++];
        }
        // for(auto it: ans) cout << it << " ";
        vector<long long> pre(n, 0);
        pre[0] = ans[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + (long long)ans[i];
        }
        long long sum = 0;
        // 1 3 6 10 15
        for(auto &req: requests){
            if(req[0] == 0) sum = (sum + pre[req[1]])%mod;
            else sum = (sum + pre[req[1]] - pre[req[0]-1])%mod;
        }
        return (int)sum%mod;
    }
};