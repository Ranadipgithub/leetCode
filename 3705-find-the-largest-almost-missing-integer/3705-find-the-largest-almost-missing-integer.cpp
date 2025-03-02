class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans1 = nums[0];
        int ans2 = nums[n-1];
        bool fg1 = true, fg2 = true;
        if(n == 2 && nums[0] == nums[1] && k == 1) return -1;
        if(n == 2 && nums[0] != nums[1] && k == 1) return *max_element(nums.begin(), nums.end());
        map<int, int> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] > maxi && mpp[nums[i]]==1){
                maxi = nums[i];
            }
        }
        if(k == 1) return maxi;
        if(n == k) return *max_element(nums.begin(), nums.end());

        for(int i = 1;i<=n-1; i++){
            if(nums[i] == ans1){
                fg1 = false;
                break;
            }
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i] == ans2){
                fg2 = false;
                break;
            }
        }
        if(ans1 == ans2) return -1;
        if(fg1 && fg2) return max(ans1, ans2);
        else if(fg1 && !fg2) return ans1;
        else if(!fg1 && fg2) return ans2;
        else return -1;
    }
};