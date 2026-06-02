class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int finish1 = max(land, waterStartTime[j]) + waterDuration[j];
                int water = waterStartTime[j] + waterDuration[j];
                int finish2 = max(water, landStartTime[i]) + landDuration[i];
                ans = min({ans, finish1, finish2});
            }
        }
        return ans;
    }
};