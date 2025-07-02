class Solution {
public:
    bool isPossible(int idx, vector<int>& temp, vector<int>& nums, int k) {
        if (temp.empty()) return true;
        bool fg = true;
        int i = temp.size() - 1;
        while (i >= 0) {
            if (abs(nums[idx] - temp[i]) == k) fg = false;
            i--;
        }
        return fg;
    }

    int solve(int idx, vector<int>& nums, int k, vector<int>& temp) {
        if (idx == nums.size()) {
            return temp.empty() ? 0 : 1; 
        }

        int take = 0;
        if (isPossible(idx, temp, nums, k)) {
            temp.push_back(nums[idx]);
            take = solve(idx + 1, nums, k, temp);
            temp.pop_back();
        }

        int notTake = solve(idx + 1, nums, k, temp);
        return take + notTake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        return solve(0, nums, k, temp);
    }
};
