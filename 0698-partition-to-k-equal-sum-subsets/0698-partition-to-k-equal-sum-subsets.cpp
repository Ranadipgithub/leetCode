class Solution {
public:
    bool solve(int i, int target, int val, int k, vector<int>&visited, vector<int>&nums){
        if(k == 0) return true;
        if(target == 0) return solve(0, val, val, k-1, visited, nums);
        if(i >= nums.size()) return false;
        bool take = false;
        if(target >= nums[i] && !visited[i]){
            visited[i] = true;
            take = solve(i+1, target-nums[i], val, k, visited, nums);
            if(take) return true;
            visited[i] = false;
        } 
        bool skip = solve(i+1, target, val, k, visited, nums);
        return take || skip;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k) return false;
        int val = sum/k;
        vector<int> visited(n, false);
        sort(nums.rbegin(), nums.rend());
        return solve(0, val, val, k, visited, nums);
    }
};