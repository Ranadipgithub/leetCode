class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = difficulty.size();

        int total = 0;
        for(int i = 0;i<n;i++){
            int currProfit = 0;
            for(int j = 0;j<m;j++){
                if(difficulty[j] <= worker[i]){
                    currProfit = max(currProfit, profit[j]);
                }
            }
            total += currProfit;
        }
        return total;
    }
};