class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < classes.size(); ++i) {
            double pass = classes[i][0];
            double total = classes[i][1];
            double profit = (pass + 1) / (total + 1) - pass / total;
            pq.push({profit, i});
        }

        while (extraStudents > 0) {
            int classIndex = pq.top().second;
            pq.pop();

            classes[classIndex][0]++;
            classes[classIndex][1]++;

            double pass = classes[classIndex][0];
            double total = classes[classIndex][1];
            double newProfit = (pass + 1) / (total + 1) - pass / total;
            pq.push({newProfit, classIndex});
            extraStudents--;
        }
        double totalRatio = 0.0;
        for (const auto& c : classes) {
            totalRatio += (double)c[0] / c[1];
        }
        return totalRatio / classes.size();
    }
};