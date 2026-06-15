class Solution {
public:
    pair<int, int> findMini(vector<int>&nums){
        int mini = INT_MAX, smini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < mini){
                smini = mini;
                mini = nums[i];
            } else if(nums[i] < smini){
                smini = nums[i];
            }
        }
        return {mini, smini};
    }
    long long maxRatings(vector<vector<int>>& units) {
        // 1 2 
        // 4 5 
        int n = units.size(), m = units[0].size();
        if(m == 1){
            int sum = 0;
            for(auto it: units){
                sum += it[0];
            }
            return sum;
        }
        unordered_map<int, pair<int, int>> mpp;
        vector<int>smini;
        int mini = INT_MAX;
        for(int i = 0;i<units.size();i++){
            mpp[i] = findMini(units[i]);
            smini.push_back(mpp[i].second);
            mini = min(mini, mpp[i].first);
        }
        sort(smini.begin(), smini.end());
        long long sum = accumulate(smini.begin()+1, smini.end(), 0LL);
        if(smini[0] > mini) sum += mini;
        else sum += smini[0];
        return sum;
    }
};