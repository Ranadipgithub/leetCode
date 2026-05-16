class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(2051, 0);
        for(auto &log: logs){
            int start = log[0], end = log[1]-1;
            diff[start] += 1;
            diff[end+1] -=1;
        }
        int maxi = INT_MIN, ans = -1;
        for(int i = 1;i<diff.size();i++){
            diff[i] += diff[i-1];
            if(diff[i] > maxi){
                maxi = diff[i];
                ans = i;
            }
        }
        return ans;
    }
};