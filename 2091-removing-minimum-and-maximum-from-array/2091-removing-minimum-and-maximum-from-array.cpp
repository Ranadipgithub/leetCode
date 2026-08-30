class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int miniidx = -1, maxiidx = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] == mini){
                miniidx = i;
            }
            if(nums[i] == maxi){
                maxiidx = i;
            }
        }

        int op1 = (miniidx+1) + (n-maxiidx);
        int op2 = max(miniidx+1, maxiidx+1);
        int op3 = max(n-miniidx, n-maxiidx);
        int op4 = (maxiidx+1) + (n-miniidx);
        return min({op1, op2, op3, op4});
    }
};