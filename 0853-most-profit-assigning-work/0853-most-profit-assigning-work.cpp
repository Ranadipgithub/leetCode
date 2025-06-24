class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = difficulty.size();

        priority_queue<pair<int, int>>pq;
        for(int i = 0;i<m;i++){
            pq.push({profit[i], difficulty[i]});
        }

        int total = 0;
        sort(worker.begin(), worker.end(), greater<int>());
        for(int i = 0;i<n;i++){
            while(!pq.empty() && pq.top().second > worker[i]) pq.pop();
            if(pq.top().second <= worker[i]){
                total += pq.top().first;
            }
            // if(pq.top().second <= worker[i]){
            //     total += pq.top().first;
            // } else{
            //     pq.pop();
            // }
        }
        return total;

        // int total = 0;
        // for(int i = 0;i<n;i++){
        //     int currProfit = 0;
        //     for(int j = 0;j<m;j++){
        //         if(difficulty[j] <= worker[i]){
        //             currProfit = max(currProfit, profit[j]);
        //         }
        //     }
        //     total += currProfit;
        // }
        // return total;
    }
};