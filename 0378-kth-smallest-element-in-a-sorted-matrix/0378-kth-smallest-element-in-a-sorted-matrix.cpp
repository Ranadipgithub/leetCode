class Solution {
public:
    int countSmaller(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] > mid) continue;
            if (matrix[i][n - 1] <= mid) {
                cnt += n;
            } else {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = countSmaller(matrix, mid);
            if (cnt < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
