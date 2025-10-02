class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> nums(maxi+1, 0);
        for(int i = 0;i<n;i++){
            nums[arr[i]] = 1;
        }
        int cnt = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == 0) cnt++;
            if(cnt == k) return i;
        }
        return maxi + (k-cnt);
    }
};