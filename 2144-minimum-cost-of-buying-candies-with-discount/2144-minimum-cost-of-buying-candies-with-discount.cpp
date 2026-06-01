class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int total = 0, cnt = 0;
        for(int i = n-1;i>=0;i--){
            if(cnt == 2){
                cnt = 0;
                continue;
            } else {
                total += cost[i];
                cnt++;
            }
        }
        return total;
    }
};