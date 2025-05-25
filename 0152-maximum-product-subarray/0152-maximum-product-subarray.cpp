class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int res1 = nums[0], res2 = nums[n-1];
        int maxi1=res1, maxi2 = res2;
        for(int i = 1;i<n;i++){
            if(res1 == 0) res1 = 1;
            res1 = res1*nums[i];
            maxi1 = max(maxi1, res1);
        }

        for(int i = n-2;i>=0;i--){
            if(res2 == 0) res2 = 1;
            res2 = res2*nums[i];
            maxi2 = max(maxi2, res2);
        }

        return max(maxi1, maxi2);

    }
};
