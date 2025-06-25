class Solution {
public:
    int noOfSmaller(int mid, int m, int n){
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            cnt += (mid / i > n) ? n : (mid / i);
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = noOfSmaller(mid, m, n);
            if (cnt >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
