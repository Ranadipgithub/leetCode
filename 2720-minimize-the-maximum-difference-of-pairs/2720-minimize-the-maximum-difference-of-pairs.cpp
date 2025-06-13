class Solution {
public:
    int countPairs(vector<int>& nums, int diff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= diff) {
                count++;
                i += 2; 
            } else {
                i++;
            }
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n - 1] - nums[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countPairs(nums, mid);

            if (count >= p) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};