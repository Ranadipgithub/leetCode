class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> arr(n+1, 0);
        for(int i = 0;i<m;i++){
            int l = queries[i][0], r = queries[i][1];
            arr[l] += 1;
            arr[r+1] -= 1;
        }

        for(int i = 1;i<n;i++){
            arr[i] = arr[i] + arr[i-1];
        }

        for(int i = 0;i<n;i++){
            int temp = nums[i] - arr[i];
            if(temp > 0) return false;
        }
        return true;
    }
};