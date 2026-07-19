class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int currDay, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, curr = 0;
        for(int i = 0;i<n;i++){
            if(currDay >= bloomDay[i]){
                curr++;
            } else {
                cnt += curr/k;
                curr = 0;
            }
        }
        cnt += curr/k;
        // cout << "Inside function" << cnt << endl;
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high -  low)/2;
            // cout << isPossible(bloomDay, mid, m, k) << " " << mid << endl;
            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};