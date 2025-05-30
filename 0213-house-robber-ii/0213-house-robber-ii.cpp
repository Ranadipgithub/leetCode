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
        
        // memset(t, -1, sizeof(t));
        // int case1 = solve(nums, 0, n - 1); 
        
        // memset(t, -1, sizeof(t));
        // int case2 = solve(nums, 1, n);    
        // return max(case1, case2);


        vector<int> t(n+1, 0);
        //t[i] = Max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
    }
};
