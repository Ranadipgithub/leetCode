class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0, sum2  = 0;
        for(int i = 0;i<n;i++){
            if(isPrime(i)) sum1 += nums[i];
            else sum2 += nums[i];
        }
        return abs(sum1-sum2);
    }
};