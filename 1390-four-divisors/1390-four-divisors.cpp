class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int cnt = 0, temp = 0;
            for(int j = 1;j<=sqrt(nums[i]);j++){
                if(nums[i]%j == 0){
                    if(j != nums[i] / j){
                        cnt += 2;
                        temp += j;
                        temp += nums[i]/j;
                    } else {
                        cnt++;
                        temp += j;
                    }
                }
            }
            if(cnt == 4){
                ans += temp;
            }
        }
        return ans;
    }
};