class Solution {
public:
    bool isPossible(vector<int>&candies, long long total, long long k){
        long long n = candies.size();
        long long cnt = 0;
        for(long long i = 0;i<n;i++){
            cnt += candies[i]/total;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size();
        long long low = 1;
        long long high = accumulate(candies.begin(), candies.end(), 0LL);            
        if(k > high) return 0;
        long long ans = LLONG_MIN;
        while(low <= high){
            long long mid = low + (high  - low)/2;
            if(isPossible(candies, mid, k)){
                low = mid + 1;
                ans = max(ans, mid);
            } else{
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};