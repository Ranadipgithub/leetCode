class Solution {
public:
    int solve(int start, int end, vector<int>& nums, int secondLen) {
        if (start > end || end - start + 1 < secondLen) return 0;

        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int best = 0;
        for (int i = start; i + secondLen - 1 <= end; i++) {
            int j = i + secondLen - 1;
            int sum = pre[j + 1] - pre[i];
            best = max(best, sum);
        }
        return best;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int ans = INT_MIN;

        for (int i = 0; i + firstLen - 1 < n; i++) {
            int start = i;
            int end = i + firstLen - 1;

            int firstSum = pre[end + 1] - pre[start];

            int temp = max(
                solve(0, start - 1, nums, secondLen),
                solve(end + 1, n - 1, nums, secondLen)
            );

            ans = max(ans, temp + firstSum);
        }

        return ans;
    }
};