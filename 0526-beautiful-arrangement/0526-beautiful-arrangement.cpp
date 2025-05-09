class Solution {
public:
    void perm(vector<int>& nums, int start, int& cnt) {
        if (start == nums.size()) {
            cnt++;
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            if ((nums[start] % (start + 1)) == 0 || ((start + 1) % nums[start]) == 0) {
                perm(nums, start + 1, cnt);
            }
            swap(nums[start], nums[i]);
        }
    }

    int countArrangement(int n) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        int cnt = 0;
        perm(nums, 0, cnt);
        return cnt;
    }
};
