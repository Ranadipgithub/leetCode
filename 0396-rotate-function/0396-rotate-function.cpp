class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long ini = 0, sum = 0;

        for(int i = 0; i < n; i++){
            ini += 1LL * i * nums[i];
            sum += nums[i];
        }

        long long maxi = ini;
        for(int i = 1; i < n; i++){
            ini = ini + sum - 1LL * n * nums[n - i];
            maxi = max(maxi, ini);
        }

        return (int)maxi;
    }
};