class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int cnt1 = 0, cnt2 = 0;
        if (nums[0] >= nums[1]) return false;
        if (nums[n - 2] >= nums[n - 1]) return false;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i + 1])
                return false;

            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                if (cnt2) return false; 
                cnt1++;
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                if (!cnt1) return false; 
                cnt2++;
            }
        }

        return cnt1 == 1 && cnt2 == 1;
    }
};