class Solution {
public:
    const long long mod = 1e9+7;
    const long long p = 100003;
    long long findPower(int a, int b) {
        if(b == 0) return 1;
        long long half = findPower(a, b/2);
        long long res = (half * half)%mod;
        if(b%2 == 1) res = (res * a)%mod;
        return res;
    }
    bool isPossible(int len, vector<int>&nums){
        int n = nums.size();
        if(n < len) return false;
        unordered_map<long long, int> mpp;
        long long curr = 0;
        long long pk_1 = findPower(p, len - 1);
        for(int i = 0;i<len;i++){
            curr = (curr*p + nums[i])%mod;
        }
        mpp[curr]++;
        for(int i = 0;i<n-len;i++){
            long long remove = (nums[i]*pk_1)%mod;
            curr = (curr - remove+mod)%mod;
            curr = (curr * p + nums[i+len])%mod;
            mpp[curr]++;
        }
        for(auto it: mpp){
            if(it.second == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, nums)){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};