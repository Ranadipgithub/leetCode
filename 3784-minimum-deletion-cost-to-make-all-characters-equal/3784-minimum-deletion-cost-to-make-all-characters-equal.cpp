class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        unordered_map<char, long long> mpp;
        for(int i = 0;i<n;i++){
            if(mpp.count(s[i])){
                mpp[s[i]] += (long long)cost[i];
            } else {
                mpp[s[i]] = (long long)cost[i];
            }
        }
        long long total = accumulate(cost.begin(), cost.end(), 0LL);
        long long mini = LLONG_MAX;
        for(auto it: mpp){
            mini = min(mini, total-it.second);
        }
        return mini;
    }
};