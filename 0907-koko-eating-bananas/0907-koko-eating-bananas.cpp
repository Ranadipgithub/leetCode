class Solution {
private:
    int findMax(vector<int>& v) {
        int maxi = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > maxi) {
                maxi = v[i];
            }
        }
        return maxi;
    }

    long long calTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0; 
        for (int i = 0; i < v.size(); i++) {
            // totalH += (v[i] + hourly - 1) / hourly;
            if(v[i] % hourly == 0) totalH += v[i]/hourly;
            else totalH += 1+v[i]/hourly;
        }
        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calTotalHours(piles, mid);
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};