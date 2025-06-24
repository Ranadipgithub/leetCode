class Solution {
public:
    long long getSum(int peak, int len) {
        if (peak > len) {
            long long first = peak - len;
            long long last = peak - 1;
            return (first + last) * len / 2;
        } else {
            long long ones = len - (peak - 1);
            return (1LL * peak * (peak - 1)) / 2 + ones;
        }
    }

    bool isPossible(int n, int mid, int index, int maxSum) {
        long long leftSum = getSum(mid, index);
        long long rightSum = getSum(mid, n - index - 1);
        long long total = leftSum + rightSum + mid;
        return total <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(n, mid, index, maxSum)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
