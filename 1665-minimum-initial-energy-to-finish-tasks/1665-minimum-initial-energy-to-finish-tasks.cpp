class Solution {
public:
    bool isPossible(int mid, vector<vector<int>>& tasks){
        int initial = mid;
        for(int i = 0;i<tasks.size();i++){
            if(initial >= tasks[i][1]){
                initial -= tasks[i][0];
            } else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // after = before - actual
        // before >= minimum
        // after >= min - actual
        sort(tasks.begin(), tasks.end(), [&](vector<int>&a, vector<int>&b){
            return a[1]-a[0] > b[1]-b[0];
        });
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += tasks[i][0];
        }
        int low = 0, high = 1e9;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, tasks)){
                ans = mid;
                high = mid - 1;
            } else low = mid +1 ;
        }
        return ans;
    }
};