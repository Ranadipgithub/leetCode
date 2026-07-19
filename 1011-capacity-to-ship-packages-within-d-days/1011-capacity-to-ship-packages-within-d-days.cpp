class Solution {
public:
    bool isPossible(vector<int>& weights, int capacity, int days){
        int cnt = 0, currWt = 0;
        int n = weights.size();
        for(int i = 0;i<n;i++){
            if(currWt + weights[i] <= capacity){
                currWt += weights[i];
            } else {
                cnt += 1;
                currWt = weights[i];
            }
        }
        if(currWt) cnt+=1;
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            } else low = mid +1;
        }
        return ans;
    }
};