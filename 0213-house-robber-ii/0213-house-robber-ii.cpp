class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int idx, int n) {
        if (idx >= n) return 0;
        if (t[idx] != -1) return t[idx];
        int steal = nums[idx] + solve(nums, idx + 2, n);
        int skip = solve(nums, idx + 1, n);
        return t[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        memset(t, -1, sizeof(t));
        int case1 = solve(nums, 0, n - 1); 
        
        memset(t, -1, sizeof(t));
        int case2 = solve(nums, 1, n);    
        
        return max(case1, case2);
    }
};
