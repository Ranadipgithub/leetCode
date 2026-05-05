class Solution {
public:
    bool isPossible(int mid, vector<vector<int>>& pre, int threshold){
        for(int i =mid-1;i<pre.size();i++){
            for(int j = mid-1;j<pre[0].size();j++){
                int sum = pre[i][j];
                if(i-mid >= 0) sum -= pre[i-mid][j];
                if(j-mid >= 0) sum -= pre[i][j-mid];
                if(i-mid >= 0 && j-mid >= 0) sum += pre[i-mid][j-mid];
                if(sum <= threshold) return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // 1 2 3 1 3 6
        // 1 4 2 1 5 7
        // 3 5 2 3 8 10
        // 1 2 3
        //   8 11
        //     23
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre = mat;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                pre[i][j] = pre[i][j-1] + mat[i][j];
            }
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                pre[i][j] += pre[i-1][j];
            }
        }
        int low = 1, high = min(n, m);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, pre, threshold)){
                ans = mid;
                low = mid+1;
            } else high = mid - 1;
        }
        return ans;
    }
};