class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        // 0 1 101 102 
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                long long sum = pre[j+1] - pre[i];
                long long last = sum % 10;
                if(last != x) continue;
                long long first = sum;
                while(first >= 10) first /= 10;
                if(first != x) continue;
                cnt++;
            }
        }
        return cnt;
    }
};