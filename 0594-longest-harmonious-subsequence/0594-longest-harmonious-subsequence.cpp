class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> fq;
        for(auto it: nums){
            fq[it]++;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int maxCnt = 0;
        while(j<n){
            if(nums[j]-nums[i] == 1){
                maxCnt = max(maxCnt, j-i+1);
            }
            else if(nums[j] - nums[i] > 1){
                while(j>i && nums[j]-nums[i] != 1) i++;
            }
            j++;
        }
        return maxCnt;
    }
};