class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        long long cost = 0;
        for (int i = 1; i < n; i++) {
            long long sum = neededTime[i - 1], mini = neededTime[i - 1];
            while (i < n && colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                mini = max((long long)mini, (long long)neededTime[i]);
                i++;
            }
            cost += (sum - mini);
        }
        return (int)cost;
    }
};