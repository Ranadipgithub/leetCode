class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // 3: n-3+1
        // 4: n-4+1
        // 5: n-5+1
        // (n-2) + (n-3) + (n-4) + ... + 1 = (n-2)(n-1)/2

        int n = nums.size();
        vector<int> diff;
        for(int i = 1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        // 1 1 1 2 3 4 4 5 5 
        int ans = 0;
        for(int i = 0;i<diff.size();i++){
            int cnt = 1, j = i+1;
            for(;j<diff.size();j++){
                if(diff[i] == diff[j]) cnt++;
                else break;
            }
            i = j-1;
            ans += cnt * (cnt-1)/2;
        }
        return ans;
    }
};