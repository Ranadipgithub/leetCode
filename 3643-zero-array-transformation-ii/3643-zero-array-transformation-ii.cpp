class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int cnt){
        int n = nums.size();
        int m = queries.size();

        vector<int> arr(n+1, 0);
        for(int i = 0;i<cnt;i++){
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            arr[l] += val;
            arr[r+1] -= val;
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
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int low = 0, high = m;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, queries, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};